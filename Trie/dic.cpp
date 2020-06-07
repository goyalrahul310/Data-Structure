#include<iostream>
#include<string>
#include<unordered_map>
using namespace std ;


class Node{
public:
	int data ;
	unordered_map<char ,Node*> children ;

	bool terminal ;
	Node(int d){
		data = d ;
	    terminal = false ;
	}

} ;

class trie{
public:
	Node *head ;
	trie(){
		head = new Node('\0') ;
	}
	void insert(char *w){
	Node* temp = head ;
	for(int i = 0 ; w[i]!='\0' ;i++){
		char ch1 = w[i] ;
		if(temp->children.count(ch1)){
			temp = temp->children[ch1] ;
		}
		else{
			Node* n = new Node(ch1) ;
			temp->children[ch1] = n ;
			temp = n ;
            }
	}
	temp->terminal = true ;

}


void helper(Node* temp,char* s){
	if(temp->terminal){
		cout << s << endl ;
	}

	for(auto i:temp->children){
        char ch = i.first ;
        Node* next = i.second ;
        s+=ch ;
        helper(next,s) ;
        s-=ch ;
	}
}

void print(char* s){
	Node* temp = head ;
	for(int i = 0 ; s[i] != '\0';i++){
		char ch = s[i] ;
		if(temp->children.count(ch)==0){
			cout << "No suggestion" << endl;
			insert(s) ;
			return ; 
		}
		temp = temp->children[ch] ;
	}
	helper(temp,s) ;
}
} ;




int main()
{   trie t ;
	int n ; 
	cin >> n ;
	char s[n][100] ;
	for(int i = 0 ; i<n;i++){
		cin >> s[i] ;
		t.insert(s[i]) ;
	}
	int q;
	cin >>q ;
	char sp[100] ;
	while(q--){
		cin >> sp ;
		t.print(sp) ;
	}
	return 0;
}