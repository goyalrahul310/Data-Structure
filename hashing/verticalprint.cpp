#include<iostream>
#include<map>
#include<vector>
using namespace std ;


class node{
public:
	int data ;
	node* left ;
	node* right ;
	node(int d){
		data = d;
		left = NULL ;
		right = NULL ;
	}
} ;


node* build(){
	int d ;
	cin >> d ;

	if(d==-1){
		return NULL ;
	}
	node* root = new node(d) ;
	 root->left = build() ;
	 root->right = build() ;
	
	return root ;
}

void vertical (node* root,int p,map<int,vector<int>> &m){

	if(root == NULL) return ;

	m[p].push_back(root->data) ;
	vertical(root->left,p-1,m) ;
	vertical(root->right,p+1,m) ;
	return ; 
}
int main()
{

	node* root = build() ;
	int p = 0 ;
	map<int,vector<int>> m ;
	vertical(root,p,m) ;
	for(auto s:m){
		cout << s.first << "->" ;
		for(int l:s.second){
			cout << l << "," ;
		}
		cout << endl ;
	}
	return 0;
}