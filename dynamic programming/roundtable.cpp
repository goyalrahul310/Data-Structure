#include<iostream>
using namespace std ;

int factorial(n){
	if(n==1)return 1;

	return n*factorial(n-1) ;
}


int main(){
int n,r ;
cin >> n >> r ;
int type = initial = n/r ;
int extra = n%r ;
int type1 = initial + 1 ;
int comb = 1 ;
for(int i = 0 ; i < extra ; i++){
   comb = factorial(n)/(factorial(n-type1)*factorial(type1)) ;
   n = n - type1 ;
}

for(int i = extra ; i < r ;i++){
	comb = factorial(n)/(factorial(n-type2)*factorial(type2)) ;
	n = n - type2 ;
}


cout << comb ;
}