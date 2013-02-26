#pragma once
#include <stdexcept> 
#include "Item_base.h"
using namespace std;

class Sales_item {

public:
	Sales_item(void): p(0),use(new std::size_t(1)){};
	Sales_item(const Item_base &);
	Sales_item(const Sales_item &i):p(i.p),use(i.use){
		++*use;	//add the reference 
	}
	~Sales_item(){
		decr_usr();
	}
	Sales_item& operator=(const Sales_item&);
	const Item_base* operator->() const{
		if (p) {
			return p;
		}else{
			throw std::logic_error("unbounded Sales_item");
		}
	}
	const Item_base& operator*() const{
		if (p){
			return *p;
		}else{
			throw std::logic_error("unbounded Sales_item");
		}
		
	}
private:
	Item_base  *p;     //pointer to shared item
	std::size_t *use; // pointer to the shared use count
	void decr_usr(){
		--*use;					//为什么对这个数据的操作要指针呢?，指向同一地址空间
		if ( 0 == *use){
			delete p;
			delete use;
		}
	}
};
inline bool compare(const Sales_item &lhs, const Sales_item &rhs)  
{  
       return lhs->book() < rhs->book();  
}  