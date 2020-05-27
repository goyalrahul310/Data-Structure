#include<iostream>
#include<unordered_set>
using namespace std ;


bool sumzero(int a[],int n){
	int pre = 0 ;
	unordered_set<int> s ;
	for(int i = 0 ;i < n ;i++){
		pre += a[i] ;
		if(pre == 0 or s.find(pre) != s.end()){
			return true ;
		}
		s.insert(pre) ;
	}
	return false ;
}
int main(){
	int n ;
	int *a = new int[n] ;
	cin >> n ;
	for(int i = 0 ;i < n;i++){
		cin >> a[i] ;
	}
	if(sumzero(a,n)) {
     cout << "true" ;
	}
	else{
		cout << "false" ;
	}
	return 0 ;
}