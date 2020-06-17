#include<iostream>
#include<climits>
using namespace std ;


int coinchange(int n,int dp[],int coin[]){
	if(n==1) return 0 ;
	dp[0] = 0 ;
    int p1,p2,p3 ;
	for(int i = 1 ; i<=n;i++)
	{
 		p1 = p2 = p3 = INT_MAX ;

 		if(i-coin[0] >= 0){
 			p1 = dp[i-coin[0]] + 1 ;
 		}

 		if(i-coin[1] >= 0){
 			p2 = dp[i-coin[1]] + 1 ;
 		}

 		if(i-coin[2] >= 0){
 			p3 = dp[i-coin[2]] + 1 ;
 		}
       
        dp[i] = min(p1,min(p2,p3)) ;
	
	}
	return dp[n] ; 
}
int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	int dp[n+1] ;
	int coin[] = {1,5,7} ; 
	cout << coinchange(n,dp,coin) ;
	return 0;
}