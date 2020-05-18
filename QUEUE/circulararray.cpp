#include<iostream>
using namespace std ;

class Queue1{
public:
	int cs,ms,front,rear ,*arr; 
	Queue1(int defaut_s = 7){
		cs = 0 ;
		ms = defaut_s  ;
		front = 0 ;
		rear = defaut_s - 1 ;
		arr = new int[ms]() ;

	}

	 bool isfull(){
	 	return cs == ms ;

	 }
	 bool isempty(){
	 	return cs == 0 ;
	 }

	void enqueue(int d){
		if(!isfull()){
		rear = (rear+1)%ms ;
		arr[rear] = d ;
		cs+=1 ;
	}
}

	void dequeue(){
		if(!isempty()){
			front = (front + 1)%ms ;
			cs -= 1 ;
		}
	}

	int getdata(){
		
			return arr[front] ;		
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