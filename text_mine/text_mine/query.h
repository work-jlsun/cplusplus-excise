#pragma once
#include "Query_base.h"
class WordQuery;
class NotQuery;
class OrQuery;
class AndQuery;

/*
*类分析:句柄类,所有用户通过这个句柄类访问所有的派生类
*
*/
class query { 
 	friend query operator~(const query &); 
    friend query operator|(const query &, const query &); 
 	friend query operator&(const query &, const query &); 
 public: 
 	query(const string&); //建立新的WordQuery对象 
  
 	// 管理指针及使用计数的复制控制成员 
 	query(const query &c): q(c.q), use(c.use) { ++*use; } 
 	~query() { decr_use(); } 
 	query& operator=(const query&); 
  
 	// 接口函数: 将调用相应的Query_base操作(以操作具体的派生类eval)
 	set <TextQuery::line_no> 
 		eval(const TextQuery &t) const {return q->eval(t); } 
	// 接口函数: 将调用相应的Query_base操作(以操作具体的派生类的diaplay)
 	ostream &display(ostream &os) const 
 	      { return q->display(os); } 
 private: 
 	query(Query_base *query): q(query), 
 		               use(new size_t(1)) { } 
 	Query_base *q; 
 	size_t *use; 
 	void decr_use() 
 	{ if (--*use == 0) { delete q; delete use; } } 
 }; 

inline query& 
query::operator=(const query &rhs) 
{ 
 	++*rhs.use; 
 	decr_use(); 
 	q = rhs.q; 
 	use = rhs.use; 
 	return *this; 
} 
inline ostream& 
operator <<(ostream &os, const query &q) 
{ 
 	return q.display(os); 
} 


 /*
*类分析：query_base类的一个基本类,wordquery查询出现对应单词"query_word"的行的行号的集合
*		 	
*
*/
class WordQuery :public Query_base
{
	friend query;
	//由于用户只通过query句柄类间接通过query_base类调用wordQuery，用户不直接使用wordquery对象，所以将以下接口都定义为private,但是
	//给query句柄类授予友元关系，因为query类会间接调用这些虚函数
	WordQuery(const std::string &s):query_word(s){};
	
	//每一个具体的类必须定义继承的纯虚函数,(派生类对private成员能够重新定义,但是不能使用,"基类的这种定义方式也含义就是让派生类对这些函数进行重定义")
	std::set<line_no> eval(const TextQuery &t) const{
		return t.run_query(query_word);//直接使用TexQuery类进行查询
	}
	std::ostream& display(std::ostream &os) const{
		return os << query_word;
	}
	//存储查询的单词
	std::string  query_word;
};





 /*
*类分析：NotQuery类的是对query对象的求反, 
*		 	
*
*/
 class NotQuery: public Query_base { 
	 //由于用户只通过query句柄类间接通过query_base类调用NotQuery，用户不直接使用NotQuery对象，所以将以下接口都定义为private,但是
	//给query句柄类的操作符函数授予友元关系，因为query类会通过这些操作符函数调用这些虚函数
 	friend query operator~(const query &); 
	NotQuery(query q): query(q) { } //注意，这里，query(q)就是调用的query类的query(const query &c)构造函数
  
	//每一个具体的类必须定义继承的纯虚函数,(派生类对private成员能够重新定义,但是不能使用,"基类的这种定义方式也含义就是让派生类对这些函数进行重定义")
 	set <line_no> eval(const TextQuery&) const; 
 	ostream& display(ostream &os) const 
 	      {return os  << "~("  << query << ")"; } 
 	const query query;		//用于存储!query对应的query部分
 }; 





/*
*类分析：BinaryQuery类的是对AndQuery类和OrQuery这些二元操作符的在一次抽象, 
*注:可以看到BinaryQuery没有重定义而是继承了基类Query_base的虚函数,所以也是抽象基类,不能以定义对象的方式使用		 	
*
*/
 class BinaryQuery: public Query_base
{
	
protected:
	BinaryQuery(query left, query right, std::string op):
		 lhs(left),rhs(right),oper(op){}
	std::ostream& display(std::ostream &os) const{
			return os << "(" << lhs << "" << oper << " "
					  << rhs << ")";
	}
	const query lhs,rhs;
	const std::string oper;
};





 /*
*类分析：AndQuery类, 
*	 	
*
*/
 class AndQuery: public BinaryQuery
{
	//AndQuery是其中的一个具体派生类,重定义基类中的虚函数
	//由于用户只通过query句柄类间接通过query_base类调用OrQuery，用户不直接使用OrQuery对象，所以将以下接口都定义为private,但是
	//给query句柄类的操作符函数授予友元关系，因为query类会通过这些操作符函数调用这些虚函数
	
	friend query operator&(const query&, const query&);
	AndQuery(query left, query right):
		BinaryQuery(left,right,"&"){}
	std::set<line_no> eval(const TextQuery& ) const;	//virtual set <line_no> eval(const TextQuery&) const
};



 /*
*类分析：OrQuery类
*	 	
*
*/
class OrQuery: public BinaryQuery
{
	//OrQuery是其中的一个具体派生类,重定义基类中的虚函数
	//由于用户只通过query句柄类间接通过query_base类调用OrQuery，用户不直接使用OrQuery对象，所以将以下接口都定义为private,但是
	//给query句柄类的操作符函数授予友元关系，因为query类会通过这些操作符函数调用这些虚函数
	friend query operator|(const query&, const query&);
	OrQuery(query left, query right):
		BinaryQuery(left,right,"|"){}
	std::set<line_no> eval(const TextQuery& ) const;	
};



