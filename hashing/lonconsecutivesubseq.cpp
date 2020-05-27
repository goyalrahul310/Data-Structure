//lonconsecutivesubseq.cpp

#include<iostream>
#include<unordered_set>

using namespace std ;


int longestsub(int *a,int n){
	unordered_set<int> s ;
	for(int i = 0 ; i < n ; i++){
		s.insert(a[i]) ;
	}
   int ans = 0 ,c = 0 ;
	for(int i =0 ; i < n ;i++){
		if(s.find(a[i] - 1) != s.end()){
			continue ;
		}
		else{
			int x = a[i] ;
			while(s.find(x) != s.end()){
				c++ ;
				x+=1 ;
			}
			ans = max(ans,c) ;
			c = 0 ;			
		}
	}
	return ans ;
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ;i  <n ;i++){
    	cin >> a[i] ;
    }

	cout << longestsub(a,n) ;
}