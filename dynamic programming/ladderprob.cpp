#include<iostream>
using namespace std ;


int ladderprob(int n,int k,int dp[]){
	if(n==0) return 1 ;

	if(dp[n] != 0){
		return dp[n] ;
	}

	int ways = 0 ;
	for(int i = 1 ; i<=k ;i++){
		if(n-i >=0){
			ways += ladderprob(n-i,k,dp) ;
		}
	}
	return dp[n] = ways ;
}

int ladderbottomup(int n ,int k){
	int dp[100] = {0} ;

	dp[0] = 1 ;
	for(int i = 1 ; i <=n ;i++){
		for(int j = 1 ; j <= k ;j++ ){
			if(i-j >=0){
				dp[i] += dp[i-j] ;
			}
	}
}
	return dp[n] ;
}


int ladderoptimised(int n,int k){
	int dp[100] = {0} ;

	dp[0] = dp[1] = 1 ;
	for(int i = 2 ; i <= k ;i++){
		dp[i] = 2*dp[i-1] ;
	}
	for(int i = k+1 ; i <= n ; i++ ){
		dp[i] = 2*dp[i-1] -  dp[i-k-1] ;   // dp[i-1] - dp[i-k-1] - dp[i-1]
	}
	return dp[n] ;
}
int main(int argc, char const *argv[])
{
	int dp[100] = {0};
	int n ;
	cin >> n ;
	int k ;
	cin >> k ;
	cout << ladderprob(n,k,dp) << endl ;
	cout << ladderbottomup(n,k) <<endl ;
	cout << ladderoptimised(n,k) ;

	return 0;
}