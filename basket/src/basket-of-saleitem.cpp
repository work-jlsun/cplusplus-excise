// basket-of-saleitem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sales_item.h"
#include "Item_base.h"
#include "Bulk_item.h"
#include "Basket.h"
using namespace std;

void
mm(void){
	Basket basket;
	//Bulk_item *p = new Bulk_item("7-115-14554-7", 99, 3, 0.2);
	Sales_item item1(Bulk_item("7-115-14554-7", 99, 3, 0.2));		//新建并作为形参传递，并将Bulk_item clone到item1中， 
	//Sales_item item2(Item_base("7-115-14554-8", 39));				//Bulk_item("7-115-14554-7", 99, 3, 0.2)本身的构造在编译中完成，析构在推出mm函数后析构
	//Sales_item item3(Bulk_item("7-115-14554-7", 99, 1, 0.2));  
	basket.add_item(item1);  
   // basket.add_item(item2);  
  //  basket.add_item(item3);
//	basket.add_item(*p);
	//basket.display(cout);
	cout << "--------------------------------" << endl;  
    cout << "总价格是：";  
    cout << (basket.total()) << endl;  
    cout << "--------------------------------" << endl;  
//	int n;
	//cin >> n;
	//return 0;
}


int 
_tmain(int argc, _TCHAR* argv[]){

	int n;
	mm();	
	cin >> n;
	
	mm();

	cin >> n;
	system("stop");
	return 0;
}

