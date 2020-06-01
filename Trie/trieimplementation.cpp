#include<iostream>
#include<unordered_map>
using namespace std ;

class Node{
public:
	int data ;
	unordered_map<char,Node*> children ;
	bool terminal ;
	Node(int d){
		data = d ;
		terminal = false ;
	}
} ;

class trie{
	public:
		Node* root ;
		int cnt ;
		trie(){
			root = new 	Node('\0') ;
			cnt  = 0 ;
		}

		void insert(char *w){
			Node* temp = root ;
			for(int i = 0 ; w[i]!='\0';i++){
				char ch = w[i] ; 
			if(temp->children.count(ch)){
                temp = temp->children[ch] ;
			}
			else{
				Node* n = new Node(ch) ;
				temp->children[ch] = n ;
				temp = n ;
			}
		}
		temp->terminal = true ;
	}

	bool find(char *w){
		Node* temp = root ;
		for(int i = 0 ; w[i] != '\0';i++){
			char ch = w[i] ;
			if(temp->children.count(ch) == 0){
				return false ;
			}
			else{
				temp = temp->children[ch] ;
			}
		}
		return temp->terminal ;

	}

} ;



int main(){

	trie t ;
	char words[][100] = {"no","not","apple","orange"} ;
	char w[100] ;
	cin >> w ;
	for(int i = 0 ; i < 4 ;i++){
		t.insert(words[i]) ;
	}
	if(t.find(w)) {
		cout << w << " is present !!!" ;
	}
	else{
		cout << w << " is not present !!!" ;
	}
}