#include<stack>
#include<iostream>
using namespace std ;



class STACK{
public:
	stack<int> s1,s2 ;
	void enqueue(int data){
		while(!s1.empty()){
			s2.push(s1.top()) ;
			s1.pop() ;

		}
		s1.push(data) ;
		while(!s2.empty()){
			s1.push(s2.top()) ;
			s2.pop() ;
		}
	}
	int dequeue(){
		if(s1.empty()){
			return -1 ;
		}
		int x = s1.top() ;
		s1.pop() ;
		return x ;
	}
} ;
int main(){
	STACK s ;
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ;i++){
		s.enqueue(i) ;
	}
	for(int i = 0 ; i< n ;i++){
		cout << s.dequeue() <<" ";
	}
}