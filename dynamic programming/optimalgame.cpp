#include<iostream>
using namespace std ;


int dp[1000][1000] ;

int game(int a[],int i,int j){
   if(i>j) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
	int q1 = a[i] + min(game(a,i+2,j),game(a,i+1,j-1)) ;
	int q2 = a[j] + min(game(a,i,j-2),game(a,i+1,j-1)) ;
	int q = max(q1,q2) ;
	dp[i][j] = q ;
	return dp[i][j] ;
}
int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
	for(int i = 0 ; i <n ;i++){
		cin >> a[i] ;
	}


	cout << game(a,0,n-1) ;
	return 0;
}