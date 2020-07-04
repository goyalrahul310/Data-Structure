#include<iostream>
using namespace std ;



void sub(int a[],int n,int k){

	int z = 0,r=0,l=0,max_len = 0,best_l = 0  ;
	for(int i = 0 ; i<n ;i++){
		if(a[i] == 1){
			r++ ;
		}
		else if(a[i] == 0){
			z++ ;
			r++ ;
		}

		while(z>k){
			if(a[l] ==0) z-- ;
			l++ ;
		}

		int lt = r - l  ;

		if(lt>max_len){
			best_l = l ;
			max_len = lt ;
		}
	}
    cout << max_len << endl ;
	for(int i = best_l ; i < best_l+max_len ;i++){
		a[i] = 1 ;
	}

	for(int i = 0 ; i < n ; i++){
		cout << a[i] ;
	}
}

int main(){
	int n ;
	int k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i= 0 ; i < n; i++){
		cin >> a[i] ;
	}

	 sub(a,n,k) ;
}