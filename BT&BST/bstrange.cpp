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


node* insertbst(node* root,int d){
	if(root == NULL) return new node(d) ;

	if(root->data>=d){
     root->left = insertbst(root->left,d) ;
	}

	else 
		root->right = insertbst(root->right,d) ;

	return root ;

}

node* build(){
	int n ;
	cin >> n ;
	int d ;
	node *root = NULL;
	for(int i = 0 ;i < n ;i++){
		cin >> d ;
		root = insertbst(root,d) ;
	}
	return root ;
}


void range1(node* root,int a,int b){
	if(root == NULL) return ;
	if(root->data>=a && root->data<=b){
		cout << root->data << " ";
	}

	range1(root->left,a,b) ;
	range1(root->right,a,b) ;
}

void preprint(node* root){
	if(root == NULL)
		return  ;
    cout << root->data ;
	preprint(root->left) ;
	preprint(root->right) ;

}
int main(){
	node* root = build() ;
	preprint(root) ;
	range1(root,3,4) ;
}

