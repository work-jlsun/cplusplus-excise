#pragma once
#include <iostream>  
#include "Item_base.h"  

class Disc_item : public Item_base  
{  
public:  
    Disc_item(const std::string& book = "",  
              double sales_prive = 0.0,  
              std::size_t qty = 0, double disc_rate = 0.0): Item_base(book, sales_prive),  
            quantity(qty), discount(disc_rate) {}  
	//重载基类版本
    virtual  double net_price(std::size_t) const=0;//定义为虚函数  
	Disc_item(const Disc_item &b):Item_base(b),
		      quantity(b.quantity),discount(b.discount){}
	Disc_item & operator=(const Disc_item &b){
		if (this != &b){
			Item_base::operator=(b);
		}
	}
    virtual void debug(std::ostream & os  = std::cout ) const  
    {  
        Item_base::debug(os);  
        os<<"/t"<<quantity<<"/t"<<discount;  
    } 
	virtual ~Disc_item(void){
		//std::cout << "~Disc_item" << endl;
	}
protected:  
    std::size_t quantity;//purchase size for discount to apply  
    double discount;//fractional discount to apply  
};  
