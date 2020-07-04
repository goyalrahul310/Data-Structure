#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;




int lcs(string m,string n,int l1,int l2){
	int dp[100][100] ;
    string s1 = "";
	for(int i = 0 ; i <= l1 ; i++){
		for(int j = 0 ; j <= l2 ;j++){
			if(i==0 || j==0){
				dp[i][j] = 0 ;
			}

			else if(m[i-1] == n[j-1]){

				dp[i][j] = dp[i-1][j-1] + 1 ;
			}
			else if(k>0){
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1)) ;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
			}
		}
	}

	return dp[i][j] ;
}
int main(){
	string m,n ;
	cin >> m ;
	cin >> n ;
	int l1 = m.size() ;
	int l2 = n.size() ;

	string s  = lcs(m,n,l1,l2) ;
	cout << s ;
	int p = s.length() ; 
	for(int i = p ; i>=0;i--){
		cout << s[i] ;
	}
	return 0 ;
}