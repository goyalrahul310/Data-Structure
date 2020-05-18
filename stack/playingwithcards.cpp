#include<iostream>
#include<stack>
using namespace std ;

#define ll long long

void primesieve(ll *arrp,ll q){
	ll p[100000] = {0} ;
	p[2] = 1 ;
	for(ll i = 3 ; i < 100000;i+=2){
        p[i] = 1 ;
	}
	for(ll i = 3 ; i < 100000;i+=2){
		for(ll j = i*i ; j < 100000;j+=i ){
			p[j] = 0 ;
		}
	}

   ll j=0;
	
	for(ll i = 0 ;i<100000;i++){
		if(p[i] == 1){
			arrp[j] = i ;
			j++;
			if(j==q) break;
		}
		
	}
}



    
int main(){
	stack<int> c,d,e ; 
	ll n,q ;
	cin >>n  >> q ;
	ll a[n] ;
	for(ll i =0 ; i <n ;i++){
		cin >> a[i] ;
		c.push(a[i]) ;
	}

	ll arrp[q] ;
	primesieve(arrp,q) ;
	for(ll i = 0 ;i < q ;i++){
		if(c.empty()) break ;
		while(!c.empty()){
		if(c.top()%arrp[i] == 0)
           d.push(c.top()) ;
        else
			e.push(c.top()) ;
			
		c.pop() ;
       while(!d.empty()) {cout << d.top() ;  d.pop() ;} 
       c = e ;
       while(!e.empty())
        e.pop() ;		
	}
}

while(!c.empty()){
	cout << c.top() ;
	c.pop() ;

}


}