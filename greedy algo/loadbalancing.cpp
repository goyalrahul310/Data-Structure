#include<iostream>
#include<climits>
using namespace std ;


int main(){
	int n ;
	cin >> n ;
	int d ,a[n];
	
	int load = 0,max_load = INT_MIN ,diff = 0; 
	for(int i = 0 ; i < n ;i++){
		cin >> a[i] ;
        load += a[i] ;
	}

	if(load%n != 0){
		cout << -1 ;
		return 0;
	}
    int ans ;
    load = load/n ;
	for(int j = 0 ; j < n ; j++){
      diff += (a[j] - load) ;

      ans = abs(diff) ;
      max_load = max(max_load,ans) ;
	}
    
    cout << max_load ;



}