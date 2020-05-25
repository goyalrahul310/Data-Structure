#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;



int main(){
 unordered_map<string,vector<string>> phonebook ;

 phonebook["rahul"].push_back("9898") ;
 phonebook["sanju"].push_back("8898") ;
 phonebook["sachin"].push_back("7898") ;
 phonebook["rahul"].push_back("9898") ;
 phonebook["saurav"].push_back("0898") ;
 phonebook["rahul"].push_back("4898") ;
 for(auto s:phonebook){
 	cout<<s.first << -> ;
 	for(auto p:s.second){
 		cout << p << "," ;
 		 	}
 }

}
