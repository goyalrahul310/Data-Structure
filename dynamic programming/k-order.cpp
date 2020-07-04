#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;




int lcs(int m[],int n[],int l1,int l2,int k){
	int dp[100][100] ;
    string s1 = "";
	for(int i = 0 ; i <= l1 ; i++){
		int t  = k ; 
		for(int j = 0 ; j <= l2 ;j++){
			if(i==0 || j==0){
				dp[i][j] = 0 ;
			}

			else if(m[i-1] == n[j-1]){

				dp[i][j] = dp[i-1][j-1] + 1 ;
			}
			else if(t>0){
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1)) ;
				t-- ;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
			}
		}
	}

	return dp[l1][l2] ;
}
int main(){
	int l1,l2,k ;
	cin >> l1>>l2>>k ;
    int a[l1],b[l2] ;
	for(int i = 0 ; i <l1;i++){
		cin >> a[i] ;
	}
	for(int j = 0 ; j < l2 ;j++){
		cin >> b[j] ;
	}
	int s  = lcs(a,b,l1,l2,k) ;
	cout << s ;
	
	return 0 ;
}