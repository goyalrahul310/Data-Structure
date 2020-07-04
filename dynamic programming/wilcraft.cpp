#include<iostream>
using namespace std ;

string pattern,text ;



void patt(int i,int j){

	int len1 = text.size() ;
	int len2 = pattern.size() ;

	if(i == len1 && j == len2){
		cout << 1 ;
		return ;
	}

	if(i >= len1 || j >= len2){
		return ;
	}
	else if(text[i] == pattern[j] || pattern[j] == '?'){
		patt(i+1,j+1);
	}

	else if(pattern[j] == '*'){
		patt(i+1,j) ;
		patt(i,j+1) ;
	}
}
int main(int argc, char const *argv[])
{
   cin >> text ;
   cin >> pattern ;
	patt(0,0) ;
	return 0;
} 

