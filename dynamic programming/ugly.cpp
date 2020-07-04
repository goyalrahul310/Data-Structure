#include<iostream>
using namespace std ;

long long int dp[1000] = {0} ;

long long int ugly(long long int  n){
	dp[1] = 1 ;
	long long int i2,i3,i4 ; 
	i2 = i3 = i4 = 1;
	for(long long int i = 2 ; i <=n ;i++){
	 	dp[i] = min(2*dp[i2],min(3*dp[i3],5*dp[i4])) ;
	 	if(dp[i] == 2*dp[i2]) i2++ ;
	 	if(dp[i] == 3*dp[i3]) i3++ ;
	 	if(dp[i] == 5*dp[i4]) i4++ ;
        
            
	}
	return dp[n] ;
	 	
}


int main(){
	long long int t ;
	long long int n ;
	cin >> t ;
	while(t--){
		cin >> n ;
		cout << ugly(n) << endl ; ;

	}

}