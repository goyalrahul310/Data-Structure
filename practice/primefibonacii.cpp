#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;




bool isprime(int x){
	if(x%2==0 && x>2){
		return false ;
	}

	for(int i = 2 ; i*i<=x ;i++){
		if(x%i == 0)
			return false ;
	}
	return true ;
}
void fun(int n1,int n2){
	vector<int>   l,l2,l3;     
	for(int i = n1 ; i <=n2 ;i++){
          if(isprime(i)){
          	l.push_back(i) ;
          }

	}

	

	int sz = l.size() ;
	for(int i = 0 ; i < sz ;i++){
		for(int j = 0 ; j < sz ;j++){
			if(i!=j){
				string t = to_string(l[i]) + to_string(l[j]) ;
				l2.push_back(stoi(t)) ;
			}

		}
	}

	sort(l2.begin(),l2.end()) ;


	for(int i = 0  ; i < l2.size() ;i++){
		if(isprime(l2[i])){
			l3.push_back(l2[i]) ;
			
		}
	}
	 vector<int>::iterator ip; 
  

    // Using std::unique 
    ip = std::unique(l3.begin(), l3.begin() + l3.size()); 
     l3.resize(std::distance(l3.begin(), ip)); 
	 
    long long int fib[l3.size()+1] ;
    fib[0] = l3[0] ;
    fib[1] = l3[l3.size()-1] ;
    cout << fib[0] << fib[1] << endl;
    long long int  x1 ;
	for(int i = 2 ; i < l3.size() ;i++){
		 fib[i] = fib[i-1] + fib[i-2] ;
		 x1 = fib[i] ;

	}
	cout << x1 ; 

}
int main(int argc, char const *argv[])
{
	int n1,n2 ;
	cin >> n1 >> n2 ;
	 fun(n1,n2) ;
	return 0;
}