//sone postion are blocked we have to find the no of ways to reach the final destibation

#include<iostream>
using namespace std ;

int grid(int r,int c,int dp[100][100]){
	if(dp[0][0] == -1) return 0 ;

   // 1 row
	for(int i = 0 ; i < c ; i++){
      if(dp[0][i] == -1) break ;

      dp[0][i] = 1 ;
	}
    // 1 col 
	for(int i = 0 ; i < r ;i++){
		if(dp[i][0] == -1) break ;

		dp[i][0] = 1 ;
	}

	for(int i = 1 ; i < r ;i++){
		for(int j = 1 ; j < c ;j++){
			if(dp[i][j] == -1) continue ;
            
            dp[i][j] = 0 ;
			
			if(dp[i][j-1] != -1 )
			  dp[i][j] =  dp[i][j-1] ;
			
			if(dp[i-1][j] != -1)
				dp[i][j] = dp[i][j] + dp[i-1][j] ;

		}

	}

	if(dp[r-1][c-1] == -1) return 0 ;

	return dp[r-1][c-1] ; 
}

int main(){
	int r,c,block ;
    int x,y ;
	cin >> r >> c >> block ;
    int dp[100][100] = {0} ;
	for(int i = 0 ; i < block ;i++){
		cin >> x >> y ;

		dp[x-1][y-1] = -1 ;
	}

    cout << grid(r,c,dp) ;


}