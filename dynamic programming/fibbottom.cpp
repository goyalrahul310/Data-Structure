#include<iostream>
using namespace std ;






int main(){
	int a = 0 ,b = 1 ;
	int n ;
	cin >> n ;
	if(n==0 || n==1){
		cout << n ;
		return 0 ;
	}
   int c ;
	for(int i = 2 ; i <=n ;i++){
		c = a+b ;
		a = b;
		b = c ;
	}

	cout << c ;

}