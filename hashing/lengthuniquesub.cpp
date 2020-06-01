//sum of length of unique subarray
#include<iostream>
#include<unordered_map>

using namespace std ;


void subarray(int *a,int n){
	int j = 0 ;
    int ans = 0 ; 
	unordered_map<int> m ;
	for(int i = 0; i<n;i++){
		while(j<n and m.find(a[i]) != m.end()){
			m.insert(a[i]) ;
			j++ ;
		}
		ans+= ((j-i+1)*(j=i+2))/2 ; 
		m.erase(a[i]) ;
	}
	cout << ans ;
}
int main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ;i<n;i++){
		cin >> a[i] ;
	}

	subarray(a,n) ;
}