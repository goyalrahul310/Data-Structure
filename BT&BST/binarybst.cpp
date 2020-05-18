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



int levelsum(node*root,int k){
	static int sum = 0 ;
	if(root == NULL) return 0;
	if(k==0){
		sum += root->data ;
	}

	levelsum(root->left,k-1) ;
	levelsum(root->right,k-1) ;

	return sum ;

}

node* build(){
	int a,b;
	cin >> a >> b ;
    node* root = new node(a) ;
	if(b==0) return root ;

	else if(b==1){
		root->left = build() ;
	}

	else if(b==2){
		root->left = build() ;
		root->right = build() ;

	}

	return root ;


}

void printpr(node* root){
	if(root == NULL) return  ;
    cout << root->data << " " ;

	printpr(root->left) ;
	printpr(root->right) ;
	//cout << root->data << " " ;

}

int main(){
node* root = build() ;
int k ;
cin >> k ;
cout << levelsum(root,k) ;
//printpr(root) ;
}