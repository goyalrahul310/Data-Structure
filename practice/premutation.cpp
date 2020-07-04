#include<climits>
#include <bits/stdc++.h>
using namespace std;

string permute(string s1,string s2){

 sort(s1.begin(),s1.end()) ;

 do{
 	if(s1 > s2) return s1 ;
 }while(next_permutation(s1.begin(),s1.end())) ;
  return "-1" ;
}


int main(int argc, char const *argv[])
{ 
	int n1,n2 ;
	cin >> n1 ;
	cin >> n2 ;
	string s1 = to_string(n1) ;
	string s2 = to_string(n2) ;
	if(s1.length()<s2.length()) {cout << -1 ; return 0;}
	else {
		cout << permute(s1,s2) ;
		return 0;
      }
}