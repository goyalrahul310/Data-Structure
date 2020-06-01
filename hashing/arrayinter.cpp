#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std ;

int main(){
	unordered_map<int,int> m ;
	int n ;
	vector<int> c ;
	cin >> n ;
	
	int a[n],b[n] ;
	for(int i =0 ; i<n ;i++){
		cin >> a[i] ;
		

	}
	for(int i = 0 ;i<n;i++){
		cin >> b[i] ;
		m[b[i]]++ ;
 
	}
     
    for(int i = 0 ;i < n ;i++)
    	if(m.count(a[i])){
    	   if(m[a[i]] > 0){
    	   	c.push_back(a[i]) ;
    	   	m[a[i]]-- ;
    	   }
    	}

    sort(c.begin(),c.end()) ;
    for(int i = 0 ;i<c.size();i++){
    	cout << c[i] << " " ;
    }

    
}