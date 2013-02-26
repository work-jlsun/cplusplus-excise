#pragma once
/*
#include "query2.h"
#include "TextQuery.h"

 class NotQuery: public Query_base { 
 	friend query operator~(const query &); 
	NotQuery(query q): query(q) { } 
  
 	// 具体类NotQuery定义所有继承而来的纯虚函数 
 	set <line_no> eval(const TextQuery&) const; 
 	ostream& display(ostream &os) const 
 	      {return os  << "~("  << query << ")"; } 
 	const query query; 
 }; 
 std::set<Query_base::line_no> NotQuery::eval(const TextQuery &file) const
 {
	 set<line_no> contain = query.eval(file);
	 set<line_no> ret_lines;
	 for (line_no n = 0; n != file.size(); n++){
		 if (contain.find(n) == contain.end() ){
			 ret_lines.insert(n);
		 }
	 }
	 return ret_lines;
 }
 */
