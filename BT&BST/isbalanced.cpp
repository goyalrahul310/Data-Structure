#include<iostream>
using namespace std ;

class node{
public:
	int data;
	node* left;
	node* right ;
	node(int d){
		data = d ;
		left = NULL ;
		right = NULL ;
	}
} ;


node* build(){
	int d ;
	cin >> d ;
	node* root = new node(d) ;
	string s ;
	cin >> s ;
	if(s == "true"){
		root->left = build() ;
	}
	cin >> s ;

	if(s=="true"){
		root->right = build() ;
	}

	return root ;

}

class Pair{
public:
   int height ;
   bool balance ;
} ;
Pair isbalanced(node* root){
	Pair p ;
	if(root == NULL) {
		p.height = 0 ;
		p.balance = true ;
		return p ;
	} 
  
	

	Pair leftp  = isbalanced(root->left) ;
	Pair rightp = isbalanced(root->right) ;
    p.height = max(leftp.height,rightp.height) + 1 ;
    if(abs(leftp.height-rightp.height) <=1 && leftp.balance && rightp.balance){
    	p.balance =  true ;
    } 
    else{
        p.balance =  false ;
    }
    return p ;

}


void preprint(node* root){
	if(root == NULL){
		return  ;
	}

	cout << root->data << " " ;
	preprint(root->left) ;
	preprint(root->right) ;
 }
int main(){
	node* root = build() ;

	if(isbalanced(root).balance) cout << "true" ;
	else cout << "false" ;

}