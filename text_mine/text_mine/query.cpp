#include "StdAfx.h"
#include "query.h"


inline 
query::query(const std::string &s):q(new WordQuery(s)),use(new size_t(1))
{
}

query 
operator~(const query &oper){
	return new NotQuery(oper);
}

query 
operator&(const query &lhs, const query &rhs){
	return new AndQuery(lhs, rhs);
}

query 
operator|(const query &lhs,const query &rhs){
	return new OrQuery(lhs, rhs);
}
 
std::set<Query_base::line_no> OrQuery::eval(const TextQuery &file) const
{
	set<line_no> right    = rhs.eval(file),
				ret_lines = lhs.eval(file);
	ret_lines.insert(right.begin(), right.end());
	return ret_lines;
}

std::set<Query_base::line_no> AndQuery::eval(const TextQuery &file) const
{
	set<line_no> right = rhs.eval(file),
					  left = lhs.eval(file);
	std::set<line_no> ret_lines;

	for(set<line_no>::const_iterator iter = right.begin(); iter != right.end(); iter++ ){
		if ( left.find(*iter) != left.end() ){
			ret_lines.insert(*iter);
		}
	}
	return ret_lines;
}

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
