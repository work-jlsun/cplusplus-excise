#pragma once
#include "TextQuery.h"
#include <iostream>

/*
*���������һ����ѯ������࣬���Կ����䲻����ʲô���ݳ�Ա��query��ʹ�������������ӿ���
*		 �������������Ķ�������࣬ʹ��ʹ��query��������Ƚϼ򵥵�ʹ�ö�������࣬�������ʹ�ö���
         ʹ�á�
		 ���Կ�����������ʹ�ó������ʵ�ֶԸ��������ͳһʹ�õġ�
*		 	
*
*/
class Query_base { 
 	friend class query; 
 protected: 
 	typedef TextQuery::line_no line_no; 
 	virtual ~Query_base() { }		 
 private:								//"��������ֶ��巽ʽҲ���������������������Щ���������ض���")
 	// ������ò�ѯƥ����е��кż��� 
 	virtual set <line_no> 
 		eval(const TextQuery&) const = 0; 
  
 	// ��ӡ��ѯ 
 	virtual ostream& 
		display(ostream& = cout) const = 0; 
 }; 