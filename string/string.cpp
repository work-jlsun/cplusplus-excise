
/*
*about:this code are writing in the visual studio 2010
*if you want to test in other ide,you should do a little 
*change
*
*/


/*String 类的
*			默认构造函数
*			赋值构造函数
*			赋值构造函数
*			析构函数
*
*/
/*
#include "stdafx.h"
#include <iostream>
//#include <string>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char *str = NULL );
	String(const String &other);
	~String(void);
	String & operator =(const String &other);    // 类Base的赋值函数
private:
	char *m_data;
};

String::~String(void){
	delete [] m_data;
}
String::String(const char *str){
	if (NULL == str){
		m_data = new char[1];
		*m_data = '\0';
	} else{
		int length = strlen(str) + 1;
		m_data = new char[length];
		strcpy(m_data, str);
	}
}

String::String(const String &other){
	int length = strlen(other.m_data) + 1;
	m_data =  new char[length];
	strcpy(m_data,other.m_data);
}

String & String::operator = (const String &other){

	if (this  == &other){
		return *this;
	}
	delete [] m_data;	//释放类原有的内存资源
	int length = strlen(other.m_data) + 1;
	m_data = new char[length];
	strcpy(m_data,other.m_data);
	return *this;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;                 
}
*/

/*
*	虚函数，抽象基类练习	 
*			 
*			 
*			 
*
*/
/*
#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;


class Item_base{
public: Item_base(const std::string &myisbn = " ", double myprice = 0.0):
	isbn(myisbn),price(myprice){}
	virtual double net_price(std::size_t n)const
	{
		return n * price;
	}
	virtual ~Item_base(){} 
private:
	std::string isbn;
protected:
	double price;
};

class Disc_item: public Item_base{
public:
	Disc_item(const std::string &book = " ", double myprice = 0.0 , double disc = 0.0, std::size_t qty = 0):
	  Item_base(book,myprice), discount(disc), quantity(qty){}
	  double net_price(std::size_t n) const = 0;
private:
	
protected:
	std::size_t quantity;
	double discount;
};

class Bulk_item: public Disc_item{
public:
	   Bulk_item(const std::string &book = " ", double myprice = 0.0 , double disc = 0.0, std::size_t qty = 0):
	              Disc_item(book,myprice,disc,qty){}
		double net_price(std::size_t ) const;       
};

double Bulk_item::net_price(std::size_t n) const{
    
	if ( n <= quantity){
	      return n*price;
	 } else {
		 return n*price - discount * quantity * price; 
	} 
}





int _tmain(int argc, _TCHAR* argv[])
{
	Bulk_item  bitem;
	//Disc_item ditem;   //不能实例化抽象类,由于下列成员“double Disc_item::net_price(size_t) const”: 是抽象的
	return 0;                 
}

*/
/*
*说明:派生类的析构函数与基类的析构函数
*
*
*/
#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

class ClxBase
{
public:
    ClxBase() {};
    virtual ~ClxBase() { cout << "Output from the destructor of class ClxBase!" ; }
	//  ~ClxBase() { cout << "Output from the destructor of class ClxBase!" ; }  //如定义为非virtual，会导致派生类可能存在内存泄露

    virtual void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived() {};
    ~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; }; 

    void DoSomething() { cout << "Do something in class ClxDerived!" << endl; 
	};
};
int _tmain(int argc, _TCHAR* argv[]) {
	ClxBase *pTest = new ClxDerived;
	pTest->DoSomething();
	delete pTest;
	//system("stop");
	int n ;
	cin >> n;
	return 0;
}