#include<iostream>
#include<stack>
using namespace std ;



void rev(stack<int> s){
	if(s.empty()) return ;

	int x = s.top() ;
	s.pop() ;
	rev(s) ;
	cout << x << endl ;
}

int main(){
	stack<int> s ;
	int n ,d;
	cin >> n ;
	for(int i =0 ; i<n ;i++){
		cin >> d ;
		s.push(d) ;
	}

	rev(s) ;
}