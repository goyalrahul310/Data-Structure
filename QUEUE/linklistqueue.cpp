#include<iostream>
#include<list>
using namespace std ;

class Queue1{
public:
	int cs ;
	list<int> qu ;
	Queue1(){
		cs = 0 ;

	}


	 bool isempty(){
	 	return cs == 0 ;
	 }

	void enqueue(int d){
		cs+=1 ;
		qu.push_back(d) ;
	}


	void dequeue(){
		if(!isempty()){
			cs -= 1 ;
			qu.pop_front() ;
		}
	}

	int getdata(){
		
			return qu.front() ;		
	}
} ;






int main(){
	Queue1 q ;

	q.enqueue(4) ;
	q.enqueue(5) ;
	q.enqueue(6) ;
	q.enqueue(7) ;
	q.dequeue() ;
	cout << q.getdata() ;
}