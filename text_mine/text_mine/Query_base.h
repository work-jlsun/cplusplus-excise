#pragma once
#include "TextQuery.h"
#include <iostream>

/*
*类分析：是一个查询抽象基类，可以看到其不包含什么数据成员，query类使用这个抽象基类间接控制
*		 这个基本抽象类的多个派生类，使得使用query这个句柄类比较简单得使用多个派生类，便于类的使用对象
         使用。
		 可以看到句柄类就是使用抽象基类实现对各派生类的统一使用的。
*		 	
*
*/
class Query_base { 
 	friend class query; 
 protected: 
 	typedef TextQuery::line_no line_no; 
 	virtual ~Query_base() { }		 
 private:								//"基类的这种定义方式也含义就是让派生类必须对这些函数进行重定义")
 	// 返回与该查询匹配的行的行号集合 
 	virtual set <line_no> 
 		eval(const TextQuery&) const = 0; 
  
 	// 打印查询 
 	virtual ostream& 
		display(ostream& = cout) const = 0; 
 }; 