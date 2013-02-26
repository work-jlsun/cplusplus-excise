#pragma once

/*
#include "BinaryQuery.h"
class AndQuery: public BinaryQuery
{
	friend query operator|(const query&, const query&);
	AndQuery(query left, query right):
		BinaryQuery(left,right,"|"){}
	std::set<line_no> eval(const TextQuery& ) const;	
};


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
*/





