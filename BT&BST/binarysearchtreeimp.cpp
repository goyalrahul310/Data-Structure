#include<iostream>
#include<climits>
using namespace std ;

class node{
public:
	int data;
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

	if(d<root->data){
		root->left = insertbst(root->left,d) ;
	}
	else{
		root->right =insertbst(root->right,d) ;
	}
	return root ;
}

node* buildbst(){
	int d ;
	cin >> d ;
	node* root = NULL ;
	while(d != -1){
		root = insertbst(root,d) ;
		cin >> d ;
	}
	return root ;
}


bool checkbst(node* root,int minv = INT_MIN,int maxv = INT_MAX){
	if(root == NULL) return true ;

	if(minv <= root->data && root->data <= maxv && checkbst(root->left,minv,root->data) && checkbst(root->right,root->data,maxv)){
		return true ;
	}	
	return false ;
}

node* deletion(node* root,int tar){
	if(root == NULL){
		return NULL ;
	}
    
	if(root->data == tar){
		// no child
		if(root->left == NULL && root->right == NULL){
			delete root ;
			return NULL ;
		}
		//1 child
		if(root->left != NULL && root->right == NULL){
			node* t = root->left ;
			delete root ;
			return t ;
		}

		if(root->left == NULL && root->right != NULL){
			node* t = root->right ;
			delete root ;
			return t ;
		}

		// 2 child
		node* replace = root->right ;
		while(replace->left != NULL){
			replace = replace->left ;
		}
		root->data = replace->data ;
		deletion(root->right,replace->data) ;
		return root ;

	}

	else if(tar < root->data){
		root->left = deletion(root->left,tar) ;
		return root ;
	}

	else {
		root->right = deletion(root->right,tar) ;
		return root ;
	}
}

void printin(node* root){
	if(root == NULL){
		return  ;
	}

	printin(root->left) ;
	cout << root->data << " " ;
	printin(root->right) ;

}
int main(){
 	node* root = buildbst() ;
 //	printin(root) ;
 	// if(checkbst(root)) cout << "BALANCED" ;
 	// else cout << "Not Balanced" ;

 	node* r = deletion(root,3) ;
 	printin(r) ;


}