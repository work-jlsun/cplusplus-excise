#pragma once
#include <iostream>
#include "Disc_item.h"
class Bulk_item: public Disc_item
{
public:
	Bulk_item(const std::string& book = "",double sales_price= 0.0, 
		      std::size_t qty = 0, double disc = 0.0 ):
	          Disc_item(book,sales_price,qty,disc){
			  std::cout << "Bulk_item::Bulk_item\n";
			  }
    //重载基类版本
	double net_price(std::size_t n) const{
		std::cout << "Bulk_item::net_price\n";
		if (n >= quantity)  
        {  
            return n*(1 - discount)*price;  
        }  
        else  
        {  
            return n*price;  
        }  
	}
	Bulk_item(const Bulk_item &b):Disc_item(b){}
	Bulk_item & operator=(const Bulk_item &b){
		if (this != &b){
			Disc_item::operator=(b);
		}
	}
	//重载基类版本
	Bulk_item * colone() const{
		std::cout << "Bulk_item * colone()" << std::endl;	
		return new Bulk_item(*this);
	}

	~Bulk_item(void){
		std::cout << "~Bulk_item" << std::endl;	
	}
private:
	//std::size_t  min_qty;
	//double discount;
};

