#include<iostream>
using namespace std ;



int knap(int sz[],int val[],int n,int s){
	int dp[10001] ;

	for(int i = 0 ; i < n;i++){
		for(int j = s ; j>=sz[i] ;j--){
			dp[j] = max(dp[j],val[i] + dp[j-sz[i]]) ;
		}
	}
	return dp[s] ;
}

int main(){
	int n ,s;

	cin >> n >> s ;

	int sz[n], val[n] ; 
	for(int i = 0 ; i<n;i++){
		cin >> sz[i] ;
	}
	for(int j = 0 ; j<n;j++){
		cin >> val[j] ;
	}

	cout << knap(sz,val,n,s) ;

}