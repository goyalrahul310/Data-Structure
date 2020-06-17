#include<iostream>
#include<climits>
using namespace std ;


int coinchange(int n ,int coin[] ,int T,int dp[]){
	if(n==0){
		return 0 ;
	}
	if(dp[n] != 0){
		return dp[n] ;
	}

	int ans = INT_MAX ;

	for(int i = 0 ; i<T ;i++){
		if(n-coin[i] >=0){
		    int s = coinchange(n-coin[i],coin,T,dp) ;
		    ans = min(ans,s+1) ;
	}
}

	dp[n] = ans ;
	return ans ;
}
int main(){
  int n ; 
  int coin[] = {1,7,10} ;
  int T = sizeof(coin)/sizeof(int) ;
  int dp[100] = {0} ;
  cin >> n ;
  cout << coinchange(n,coin,T,dp) ;
}