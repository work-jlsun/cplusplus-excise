#pragma once
#include <set>
#include "Sales_item.h"

class Basket  
{  
    //定义multiset的比较函数  
    typedef bool (*Comp)(const Sales_item&,const Sales_item&);  
public:  
    //make it easir to type of our set  
    typedef std::multiset<Sales_item,Comp>set_type;  
    //typedefs modeled after corresponding contanier types  
    typedef set_type::size_type size_type;  
    typedef set_type::const_iterator const_iter;  
    Basket():items(compare){}//initialze the comparator  
    void add_item(const Sales_item &item){items.insert(item);}  
    size_type size(const Sales_item &i) const  
    {  
        return items.count(i);  
    }  
	void display( std::ostream &os = std::cout ) const; 
    double total() const;//sum of net prices for all items in the basket  
	virtual ~Basket(void){}
private:  
    std::multiset<Sales_item,Comp> items;  
};  

