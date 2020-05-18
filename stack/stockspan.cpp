#include<iostream>
#include<stack>
using namespace std ;



int main(){
	int n ,ans[n+1];
	cin >> n ;
	int a[n] ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}

	stack<int> s ;
	for(int day = 1 ; day <= n ;day++){
		while(!s.empty() && a[s.top()] < a[day]){
			s.pop() ;
		}

		int better = s.empty()?0:s.top() ;
		ans[day] = day - better ;
		s.push(day) ;

	}

	for(int i = 1 ;i <=n ;i++){
		cout << ans[i] << " " ;
	}
	}
