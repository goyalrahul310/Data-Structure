#include<iostream>
using namespace std ;

class node{

public:
	int data ;
	node* left ;
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
	string s ;
	node* root = new node(d) ;
	cin >> s ;
	if(s== "true"){
		root->left = build() ;
	}

	cin >> s ;
	if(s == "true"){
		root->right = build() ;
	}
	return root ;
	
}

bool chk(node* root1,node* root2){
	if(root1 == NULL && root2 == NULL){
		return true ;
	}

	if(root1 == NULL && root2 != NULL){
		return false ;
	}

	return chk(root1->right,root2->right) && chk(root1->left,root2->left) ;
}

int main(int argc, char const *argv[])
{
   node* root1 = build() ;
   node* root2 = build()  ;
   if(chk(root1,root2)) {
   	cout << "true" ;
   }  
   else{
   	cout << "false" ;
   }
	
	return 0;
}