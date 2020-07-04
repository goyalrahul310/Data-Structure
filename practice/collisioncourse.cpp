#include<iostream>
#include<algorithm>
using namespace std ;


int coll(int t,int a[],int b[],int s[]){
		int d[t] ;
	for(int i = 0 ; i < t ;i++){
		 d[i] = ((a[i]*a[i]) + (b[i]*b[i]))/(s[i]*s[i]) ;
	}
    sort(d,d+t) ;
	int c = 0 ;
	int cur = d[0] ;
	int temp = 1 ;
	cout << t ;
	cout << cur << endl;
	for(int i = 1 ; i < t ;i++){
		cout << d[i]<<endl ;
		if(cur == d[i]){
			temp++ ;
		}
		else{
			c += (temp*(temp-1))/2 ;
			temp = 1 ;
			cur = d[i] ; 
		}
	}
		c += (temp*(temp-1))/2 ;
	return c ;
}
int main(){
	int t ;
	cin >> t ;
	int a[t],b[t],s[t] ;
	for(int i = 0 ; i < t ;i++){
		cin >> a[i] >> b[i] >> s[i] ;
	}

	cout << coll(t,a,b,s) ;
}