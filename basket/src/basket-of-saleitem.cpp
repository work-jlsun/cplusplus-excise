// basket-of-saleitem.cpp : �������̨Ӧ�ó������ڵ㡣
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
	Sales_item item1(Bulk_item("7-115-14554-7", 99, 3, 0.2));		//�½�����Ϊ�βδ��ݣ�����Bulk_item clone��item1�У� 
	//Sales_item item2(Item_base("7-115-14554-8", 39));				//Bulk_item("7-115-14554-7", 99, 3, 0.2)����Ĺ����ڱ�������ɣ��������Ƴ�mm����������
	//Sales_item item3(Bulk_item("7-115-14554-7", 99, 1, 0.2));  
	basket.add_item(item1);  
   // basket.add_item(item2);  
  //  basket.add_item(item3);
//	basket.add_item(*p);
	//basket.display(cout);
	cout << "--------------------------------" << endl;  
    cout << "�ܼ۸��ǣ�";  
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

