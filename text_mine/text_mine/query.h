#pragma once
#include "Query_base.h"
class WordQuery;
class NotQuery;
class OrQuery;
class AndQuery;

/*
*�����:�����,�����û�ͨ����������������е�������
*
*/
class query { 
 	friend query operator~(const query &); 
    friend query operator|(const query &, const query &); 
 	friend query operator&(const query &, const query &); 
 public: 
 	query(const string&); //�����µ�WordQuery���� 
  
 	// ����ָ�뼰ʹ�ü����ĸ��ƿ��Ƴ�Ա 
 	query(const query &c): q(c.q), use(c.use) { ++*use; } 
 	~query() { decr_use(); } 
 	query& operator=(const query&); 
  
 	// �ӿں���: ��������Ӧ��Query_base����(�Բ��������������eval)
 	set <TextQuery::line_no> 
 		eval(const TextQuery &t) const {return q->eval(t); } 
	// �ӿں���: ��������Ӧ��Query_base����(�Բ���������������diaplay)
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
*�������query_base���һ��������,wordquery��ѯ���ֶ�Ӧ����"query_word"���е��кŵļ���
*		 	
*
*/
class WordQuery :public Query_base
{
	friend query;
	//�����û�ֻͨ��query�������ͨ��query_base�����wordQuery���û���ֱ��ʹ��wordquery�������Խ����½ӿڶ�����Ϊprivate,����
	//��query�����������Ԫ��ϵ����Ϊquery����ӵ�����Щ�麯��
	WordQuery(const std::string &s):query_word(s){};
	
	//ÿһ�����������붨��̳еĴ��麯��,(�������private��Ա�ܹ����¶���,���ǲ���ʹ��,"��������ֶ��巽ʽҲ������������������Щ���������ض���")
	std::set<line_no> eval(const TextQuery &t) const{
		return t.run_query(query_word);//ֱ��ʹ��TexQuery����в�ѯ
	}
	std::ostream& display(std::ostream &os) const{
		return os << query_word;
	}
	//�洢��ѯ�ĵ���
	std::string  query_word;
};





 /*
*�������NotQuery����Ƕ�query�������, 
*		 	
*
*/
 class NotQuery: public Query_base { 
	 //�����û�ֻͨ��query�������ͨ��query_base�����NotQuery���û���ֱ��ʹ��NotQuery�������Խ����½ӿڶ�����Ϊprivate,����
	//��query�����Ĳ���������������Ԫ��ϵ����Ϊquery���ͨ����Щ����������������Щ�麯��
 	friend query operator~(const query &); 
	NotQuery(query q): query(q) { } //ע�⣬���query(q)���ǵ��õ�query���query(const query &c)���캯��
  
	//ÿһ�����������붨��̳еĴ��麯��,(�������private��Ա�ܹ����¶���,���ǲ���ʹ��,"��������ֶ��巽ʽҲ������������������Щ���������ض���")
 	set <line_no> eval(const TextQuery&) const; 
 	ostream& display(ostream &os) const 
 	      {return os  << "~("  << query << ")"; } 
 	const query query;		//���ڴ洢!query��Ӧ��query����
 }; 





/*
*�������BinaryQuery����Ƕ�AndQuery���OrQuery��Щ��Ԫ����������һ�γ���, 
*ע:���Կ���BinaryQueryû���ض�����Ǽ̳��˻���Query_base���麯��,����Ҳ�ǳ������,�����Զ������ķ�ʽʹ��		 	
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
*�������AndQuery��, 
*	 	
*
*/
 class AndQuery: public BinaryQuery
{
	//AndQuery�����е�һ������������,�ض�������е��麯��
	//�����û�ֻͨ��query�������ͨ��query_base�����OrQuery���û���ֱ��ʹ��OrQuery�������Խ����½ӿڶ�����Ϊprivate,����
	//��query�����Ĳ���������������Ԫ��ϵ����Ϊquery���ͨ����Щ����������������Щ�麯��
	
	friend query operator&(const query&, const query&);
	AndQuery(query left, query right):
		BinaryQuery(left,right,"&"){}
	std::set<line_no> eval(const TextQuery& ) const;	//virtual set <line_no> eval(const TextQuery&) const
};



 /*
*�������OrQuery��
*	 	
*
*/
class OrQuery: public BinaryQuery
{
	//OrQuery�����е�һ������������,�ض�������е��麯��
	//�����û�ֻͨ��query�������ͨ��query_base�����OrQuery���û���ֱ��ʹ��OrQuery�������Խ����½ӿڶ�����Ϊprivate,����
	//��query�����Ĳ���������������Ԫ��ϵ����Ϊquery���ͨ����Щ����������������Щ�麯��
	friend query operator|(const query&, const query&);
	OrQuery(query left, query right):
		BinaryQuery(left,right,"|"){}
	std::set<line_no> eval(const TextQuery& ) const;	
};



