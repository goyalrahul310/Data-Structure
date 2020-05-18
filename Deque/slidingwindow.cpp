#include<iostream>
#include<deque>
using namespace std ;


int main(){

	int n ;
	cin>> n ;
	int a[n] ;
	for(int i = 0 ; i < n ;i++){
		cin >> a[i] ;
	}

	int k ,i;
	cin >> k ;
	deque<int> qu(k) ;
	for( i=0;i<k;i++){
		while(!qu.empty() && a[i] > a[qu.back()]){
			qu.pop_back() ;
		}
		qu.push_back(i) ;
	}


for( ; i < n;i++){
	cout << a[qu.front()] << " ";
    //not in current window
	while(!qu.empty() && qu.front() <= i-k){
		qu.pop_front() ;
	}

	//not usefull
	while(!qu.empty() && a[i] > a[qu.back()]){
		qu.pop_back() ;
	}

    qu.push_back(i) ;

}
  cout << a[qu.front()] ;


}