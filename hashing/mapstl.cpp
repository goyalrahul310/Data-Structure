#include<iostream>
#include<map>
using namespace std ;




int main(){
 map<string,int> m ;

 m.insert(make_pair("apple",20)) ;
 m["orange"] = 90 ;
 auto it = m.find("orange") ;

 if(it != m.end()){
    cout << "orange" << "is" << m["orange"] ;
 }
 else{
 	cout << "Not found" ;
 }

 for(auto i = m.begin() ; i!=m.end();i++){
 	cout << i->first << i->second ;
 }
 
  	m.erase("apple") ;
  
 for(auto p:m){
 	cout <<p.first << p.second; 
 }

}