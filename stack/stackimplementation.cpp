#include<iostream>
#include<vector>
using namespace std ;
template<typename T>
class stack{
private:
	vector<T> v ;
public:
	void push(T data){
		v.push_back(data) ;
	}
	void pop(){
		v.pop_back() ;
	}
	bool isempty(){
		return v.size() == 0 ;
	}
	T  top(){
		return v[v.size() -1] ;
	}




} ;

int main(){
	stack<char> s ;

	for(int i = 65 ;i < 70 ;i++)
		s.push(i) ;

	for(int i =65 ;i < 70 ;i++){
		cout << s.top() << " " ;
		s.pop() ;
	}
}
