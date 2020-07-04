#include<iostream>
#include<climits>
using namespace std ;


int dp[100] ;

int minjump(int a[],int n){
	dp[0] = 0 ;

	for(int i = 1 ; i < n ;i++){
		dp[i] = INT_MAX ;
		for(int j = 0 ; j < i ;j++){
			if(i <= j+a[j]){
				dp[i] = min(dp[i],dp[j]+1) ;
				break ;
			}
		}
	}
	return dp[n-1] ;


}

int main(int argc, char const *argv[])
{
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i <n;i++){
			cin >> a[i] ;
		}
		cout << minjump(a,n) << endl ;
	}
	return 0;
}