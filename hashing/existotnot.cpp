#include<iostream>
#include<unordered_map>
using namespace std ;

int main(){
	int T ;
	cin >> T ;
   while(T--){
   	unordered_map<int,int> m ;
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0; i<n;i++){
		cin >> a[i] ;
		m[a[i]] = i ;
	}
	int k,d ;
	cin >> k ;
    for(int i = 0 ;i < k ;i++){
      cin >> d ;
      if(m.count(d)) cout << "Yes" << endl ;
      else cout << "No" << endl ;
    }
}
}