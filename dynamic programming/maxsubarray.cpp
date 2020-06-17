#include<iostream>
using namespace std ;

int maxsubarray(int a[],int n){
 	//int dp[100] = {0} ;
 	 a[0] = (a[0]>0)?a[0]:0 ;
 	int maxi = a[0];

 	for(int i = 1 ;i < n ;i++){
 		a[i] = a[i-1] + a[i] ;
 		if(a[i] < 0){
 			a[i] = 0 ;
 		}

 		maxi = max(a[i],maxi) ;
 	}
 	return maxi ;
 }


 int main(){
 	int n ;
 	cin >> n ;
 	int a[n] ;
 	for(int i = 0 ; i < n; i++){
 	cin >> a[i] ;
 	}

 	cout << maxsubarray(a,n) ;


 }