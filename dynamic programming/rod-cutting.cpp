#include<iostream>
using namespace std ;


int  maxprofittopd(int a[],int n,int dp[]){
	if(n==0) return 0 ;

	if(dp[n] != 0){
       return dp[n] ;
	}
  int best = 0 ;
	for(int i = 1 ; i <= n ;i++){
		int net = a[i] + maxprofittopd(a,n-i,dp) ;
		best = max(best,net) ;
	}
	return dp[n] = best ; 
}

int maxprofitbottomup(int a[],int n){
	int dp[100] = {0} ;

	for(int i = 1 ; i <=n ;i++){
		int best = 0 ;
		for(int j = 1 ; j<=i ;j++){
			best = max(best,a[j] + dp[i-j]) ;
		}
		dp[i] = best ;
	}
	return dp[n] ;
}

int main(int argc, char const *argv[])
{   int n ;
	cin >> n ;
	int a[n+1] ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	int dp[100] = {0} ;
	cout << maxprofittopd(a,n,dp) ;
	cout << maxprofitbottomup(a,n) ;
	return 0;
}