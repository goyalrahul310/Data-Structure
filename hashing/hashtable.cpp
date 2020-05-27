#include<iostream>
#include<cstring>
#include "hash.h" 
using namespace std ;

int main()
{
	hashtable<int> price_menu ;
	price_menu.insert("burger",23) ;
	price_menu.insert("pepsi",24) ;
    price_menu.insert("coke",25) ;
	price_menu.insert("limca",26) ;
	price_menu.insert("burger",23) ;
    price_menu.insert("coke",25) ;
	price_menu.insert("limca",260) ;
	price_menu.erase("limca") ;
	price_menu.erase("pepsi") ;
	price_menu.print() ;
	// int *p = price_menu.search("pepsi") ;
	// if(p == NULL) cout << "not found" ;
	// else{
	// 	cout << *p ;
	// }
	// //price_menu.erase("coke") ;
	// price_menu["limca"] = 90 ;
	// price_menu["limca"] += 10 ;
	// cout << price_menu["limca"] ;

}
	
