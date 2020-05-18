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



class pair1{
public:
	node* head ;
	node* tail ;
} ;

pair1 flatten(node* root){
	pair1 l ;
	if(root == NULL) {
		
		l.head = l.tail = NULL ;
		return l ;
	}

	else if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l ;

	}
	else if(root->left != NULL && root->right == NULL){
		pair1 leftll = flatten(root->left) ;
		leftll.tail->right = root ;
		l.head = leftll.head ;
		l.tail = root ;
		return l ; 
	}

	else if(root->right != NULL && root->left == NULL ){
		pair1  rightll = flatten(root->right) ;
		root->right = rightll.head ;

		l.head = root ;
        l.tail = rightll.tail ;
        return l ;
	}

	pair1 leftll = flatten(root->left) ;
	pair1 rightll = flatten(root->right) ;
	leftll.head->right = root ;
	root->right = rightll.head ;

	l.head = leftll.head ;
	l.tail = rightll.tail ;
	return l ;
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
 
  
 	//printin(r) ;
 	node*head = flatten(root).head ;
 	while(head!=NULL){
 		cout << head->data << " " ;
 		head = head->right ;
 	}


}