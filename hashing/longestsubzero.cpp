#include<iostream>
#include<unordered_map>
using namespace std ;

int longsubarray(int *a,int n,int k){
	int pre = 0 ;
	int len = 0 ;
	unordered_map<int,int> s ;

	for(int i =0 ; i<n;i++){
		pre+= a[i] ;
		if(a[i] == k and len == 0) {
			len = 1 ;
		}
		if(pre == k){
			len = max(len,i+1) ;
		}
		if(s.find(pre-k) != s.end()){
			len = max(len,i - s[pre]) ;
		}
		else{
			s[pre] = i ;
			//cout << s[pre] ; 
		}
		
		
	}
	return len ;
}

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ;i <n;i++){
		cin >> a[i] ;
	}
	int k = 3  ;
    int l = longsubarray(a,n,k) ;
    cout << l ;
	return 0;
}