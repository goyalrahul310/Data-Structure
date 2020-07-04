#include<iostream>
#include<vector>
using namespace std ;

int dp[100] ;

vector<int> pr(256, -1); 

int countd(string a,int n){
	dp[0] = 1; 
	for(int i = 1 ; i <=n ;i++){
		dp[i] = 2*dp[i-1] ;

		if(pr[a[i-1]] != -1){
			dp[i] = dp[i] - dp[pr[a[i-1]]] ;
		}

		pr[a[i-1]] = i-1 ;
	}
	return dp[n] ;
}

int main(){

	string a ;
	cin >> a ;
	int n = a.size() ;


	cout << countd(a,n) ;
}