#include<iostream>
#include<map>
#include<climits>
using namespace std ;

void maxfreq(int *a,int n){
	map<int,int> m ;
	int out = 0 ;
	int max1 = INT_MIN ;
	for(int i = 0 ;i < n;i++){
		m[a[i]]+=1 ;
		if(m[a[i]] > max1){
			max1  = m[a[i]] ;
			out = a[i] ;
		}

	}

cout << out ; 
}
int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ;i++){
		cin >> a[i] ;
	}
	maxfreq(a,n) ;
	return 0;
}