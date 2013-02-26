#include "StdAfx.h"
#include "Basket.h"


double Basket::total() const 
{
	double sum = 0;
	for(const_iter iter = items.begin(); 
		iter != items.end(); 
		iter = items.upper_bound(*iter)){
			sum += (*iter)->net_price(size(*iter));
	}
	return sum;
}



void Basket::display( std::ostream & os) const {
	double sum = 0;
	for(const_iter iter = items.begin(); 
		iter != items.end(); 
		iter = items.upper_bound(*iter)){
			os << "isbn:" << (*iter)->book() << "\tocuurs:\t" << size(*iter) 
				<< " times\t" << "sum:" << (*iter)->net_price(size(*iter)) << std::endl;
		//	sum = (*iter)->net_price(size(*iter));
	}
}