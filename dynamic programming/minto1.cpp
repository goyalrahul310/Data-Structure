#include<iostream>
#include<climits>
using namespace std ;



// min steps to 1
//bottom up approach ;
int main(int argc, char const *argv[])
{
	int n ;
	cin >>n ;
	int dp[n+1] ;
	dp[1] = 0 ;
	int p1 ,p2,p3;
	if(n==1) {cout << 0 ; return 0 ; }
	for(int i = 2 ; i<=n;i++){
		if(i%2 == 0){
			int t = i/2 ;
			 p1 = dp[t] ; 
		}
		else{
			p1 = INT_MAX ;
		}

		if(i%3 == 0){
			int t1 = i/3 ;
			 p2 = dp[t1] ;
		}
		else{
			p2= INT_MAX ;
		}

		p3 = dp[i-1] ;

		dp[i] = min(p1,min(p2,p3)) + 1 ;
		
	}
    
     cout << dp[n] ;
	
	return 0;
}