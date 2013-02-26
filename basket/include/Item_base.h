#pragma once
#include <string>
#include <iostream>
//this is the most common data of book, isbn and price

class Item_base
{
public:
	  Item_base(const std::string &book = " " ,double pric = 0.0 ): 
	  isbn(book), price(pric){
		//std::cout << "Item_base(const std::string &,double)\n";
	  }
	  std::string book() const{
		return isbn;
	  }
	  virtual double net_price(std::size_t n) const{
		std::cout << "Item_base::net_price\n";
		return n * price;
	  }
	  Item_base(const Item_base & ib):isbn(ib.isbn),price(ib.price){
		 //std::cout << "Item_base(const Item_base &)\n";
	  }
	  Item_base& operator=(const Item_base& rhs)  
      {  
        isbn = rhs.isbn;  
        price = rhs.price;  
        std::cout << "Item_base::operator=()" << std::endl;  
        return *this;  
      } 
	  virtual void debug(std::ostream & os = std::cout) const{
		os << isbn << "/t" << price; 
	  }
	  virtual Item_base * colone() const {
			return new Item_base(*this);
	  }
	   virtual ~Item_base(void){
		 //std::cout << "~Item_base(void)\n";	   
	   }
private:
	std::string isbn;
protected:
	double price;
};

