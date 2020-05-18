#include<iostream>
#include<stack>
#include<string>
using namespace std ;

int main(){
	string str,res = "/" ;

	string dir ;
	stack<string> s,s1 ;
    cin >> str ;
	int n = str.length() ;
	for(int i = 0 ; i<n;i++){
     	dir.clear() ;

		while(str[i] == '/'){
			i++ ;
		}

		while(i < n && str[i] != '/'){
			dir.push_back(str[i]) ;
			i++ ;
		}

		if(dir.compare("..") == 0){
			if(!s.empty()){
				s.pop() ;
			}
		}

		else if(dir.compare(".") == 0)
			continue ;

		else if(dir.length() != 0){
			s.push(dir) ;
		}


	}

	//reverse the stack

	while(!s.empty()){
		s1.push(s.top()) ;
		s.pop() ;
	}
	while(!s1.empty()){
		string t = s1.top() ;
		if(s1.size() != 1)
			res.append(t + '/') ;
		else
			res.append(t) ;
		s1.pop() ;
	}


    cout << res ;

}