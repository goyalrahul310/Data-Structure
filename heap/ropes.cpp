#include<iostream>
#include<queue>
#include<vector>
using namespace std ;

int fun(int *arr,int n)
{
	priority_queue<int,vector<int>,greater<int> p(arr,arr+n) ;
	int c = 0 ;
	while(p.size()>1){
		int f = p.top() ;
		p.pop ;
		int s = p.top() ;
		p.pop() ;
		c+=(f+s) ;
		p.push(f+s) ;

	}
	return c ;
}
int main(){

	int n ;
	cin >> n ;
	int *a = new int[n]() ;

	for(int i = 0 ;i < n ;i++){
		cin >> a[i] ;
	}
	cout << fun(a,n) ;
}