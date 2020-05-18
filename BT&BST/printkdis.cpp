#include<iostream>

using namespace std ;

class node{
public:
	int data ;
	node* left ;
	node* right ;
	node(int d){
	d = data ;
	left = NULL ;
	right = NULL ;
}
} ;


node* buildtree(){
	int d ;
	cin >> d ;
	if(d==-1){
		return NULL ;
	}
    node* root = new node(d) ;
	root->left = buildtree() ;
	root->right = buildtree() ;

	return root ;

}
void printsub(node* root,int k){

}


printanc(node* root,node* tar ,int k)



int main(){
 node* root = buildtree()
 node* tar = root->left ;
 printanc(root,tar,2) ;



}