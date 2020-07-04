#include<iostream>
using namespace std ;



int lis(int a[],int n){
	int dp[100] ;
    int best = 0 ;
	for(int i = 0 ; i < n ;i++){
		dp[i] = 1 ;
		for(int j = 0 ; j < i ;j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i],dp[j]+1) ;
			}
		}
		best = max(best,dp[i]) ;

	}
	return best ;
}
int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ;i++){
		cin >> a[i] ;
	}
	cout << lis(a,n) ;
	return 0;
}