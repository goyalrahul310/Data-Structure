#include<iostream>
using namespace std ;



int hoopt(int a[100][100],int m,int n){
	int i = 0,j=0 ;
	int s = 0 ;
	if(a[0][0] == 1){
		s = 1 ;
	}
	while(i<m && j<n){
		    if(a[i][j+1] > a[i+1][j]){
			s += max(a[i][j+1],a[i+1][j]) ;
			j = j+1 ;
		    }
		    else{
		    	s += max(a[i][j+1],a[i+1][j]) ;
			    i = i+1 ;
		    }
		}

    if(i >= m){
    	i = i-1 ;
    }
    if(j >= n){
    	j = j-1 ;
    }

	while(i>=0 && j>=0){
       if(a[i][j-1] > a[i-1][j]){
			s += max(a[i][j-1],a[i-1][j]) ;
			j = j-1 ;
		    }
		    else{
		    	s += max(a[i][j+1],a[i+1][j]) ;
			    i = i-1 ;
		    }
	}
	return s ;
	}



int main(){
	int m,n ;
	cin >> m >> n ;
	int a[100][100] ;
	for(int i =0 ; i<m;i++){
        for(int j = 0 ;j < n ;j++){
        	cin >> a[i][j] ;
        }
	}

	cout << hoopt(a,m,n) ;
}