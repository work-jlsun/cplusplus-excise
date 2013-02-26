#pragma once
/*
#include "BinaryQuery.h"

class OrQuery: public BinaryQuery
{
	friend query operator|(const query&, const query&);
	OrQuery(query left, query right):
		BinaryQuery(left,right,"|"){}
	std::set<line_no> eval(const TextQuery& ) const;	
};


std::set<Query_base::line_no> OrQuery::eval(const TextQuery &file) const
{
	set<line_no> right    = rhs.eval(file),
				ret_lines = lhs.eval(file);
	ret_lines.insert(right.begin(), right.end());
	return ret_lines;
}
*/


