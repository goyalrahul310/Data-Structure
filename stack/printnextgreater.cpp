#include<stack>
#include<iostream>
using namespace std ;


void printmax(int a[100],int n){
	stack<int> s ;
    s.push(a[0]) ;
    for(int i = 1 ; i< n;i++){
    	while(!s.empty() && a[i] > s.top()){
    		cout << a[i] << " " ;
    		s.pop() ;
    	}
    	s.push(a[i]) ;
    }

    while(!s.empty()){
    	cout << -1 << " " ;
    	s.pop() ;
    }
}


int main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ;i <n;i++){
		cin >> a[i] ;
	}

	printmax(a,n) ;
}