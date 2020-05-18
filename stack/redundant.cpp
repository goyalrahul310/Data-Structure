#include<iostream>
#include<stack>
#include<cstring>
using namespace std ;



bool chk(string str){
	stack<char> s ;
	
	for(int i = 0 ; i < str.length() ;i++){
		if(str[i] == '('){
			s.push(str[i]) ;
		}
		
		else if(str[i] == ')'){
			if(s.top() != '('){
            while(s.top() != '('){
            	s.pop() ;
            }
            s.pop() ;
		    }
		    else return false ;
		}

		
		else{
			s.push(str[i]) ;
		}
	}

	return true ;

}

int main(){
	string str ;
	
	int t ;
	cin >> t ;
	 while(t--){
	 	cin >> str ;
		if(chk(str)){
			cout << "Not Duplicates" << endl ;

		}
		else {
			cout << "Duplicate" << endl ;
		}
}

}

