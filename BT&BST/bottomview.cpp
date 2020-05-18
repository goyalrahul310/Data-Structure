#include<iostream>
#include<map>
#include<queue>
using namespace std ;

class node{
public:
	int data;
	node* left ;
	node* right ;
	int hd ;
public:
	node(int d){
		data = d ;
		left = NULL ;
		right = NULL ;
	}
} ;



node* buildlevel(){
	int c1,c2 ;
	queue<node*> q ;
	int d ;
	cin >> d ;
	node* root = new node(d) ;
	q.push(root) ;
	while(q.size()){
		node* f = q.front() ;
		q.pop() ;
		cin >> c1 >> c2 ;
		if(c1!=-1){
			f->left = new node(c1) ;
			q.push(f->left) ;

		}
		if(c2!=-1){
			f->right = new node(c2) ;
			q.push(f->right) ;
		}
	}
	return root ;
	}

void bottomview(node* root){

	if(root == NULL) return ;
	int hd = 0 ;
	root->hd = hd ;
	map<int,int> m ;
	queue<node*> q ;
	q.push(root) ;
	while(q.size()){
		hd = root->hd ;
		m[hd] = root->data ;
		if(root->left){
			root->left->hd = hd-1 ;
			q.push(root->left) ;
		}
		if(root->right){
			root->right->hd = hd+1 ;
			q.push(root->right) ;
		}

		q.pop() ;
		root = q.front() ;
	}
	for(auto i = m.begin();i!=m.end();i++){
		cout << i->second << " " ;
	}
}

int main(int argc, char const *argv[])
{
    node* root = buildlevel() ;
    bottomview(root);

	return 0;
}


// node*buildtree()
// {


// int d;
// cin>>d;

// node*root = new node(d);
// queue<node*> q;
// q.push(root);

// while(!q.empty()){

//     node*f = q.front();
//     q.pop();
//     int c1,c2;
//     cin>>c1>>c2;

//     if(c1!=-1){
//         f->left = new node(c1);
//         q.push(f->left);
//     }
//     if(c2!=-1){
//         f->right = new node(c2);
//         q.push(f->right);
//     }
// }
// return root;
// }

// node*bview(node*root)
// {
//     int hd=0;
//     if(root==NULL)
//     {
//         return NULL;
//     }
//     queue<node*>q;
//     map<int ,int> m;
    
//     root->hd=hd;
//     q.push(root);
//     while(q.size())
//     {
//         hd=root->hd;
        
//             m[hd]=root->data;
    
//         if(root->left)
//         {
//             root->left->hd=hd-1;
//             q.push(root->left);
//         }
//          if(root->right)
//         {
//             root->right->hd=hd+1;
//             q.push(root->right);
//         }
//         q.pop();
//         root=q.front();


//     }
//      for(auto i=m.begin();i!=m.end();i++) 
//     { 
//         cout<<i->second<<" "; 
//     } 
// }
// int main() {
//     node* root=NULL;
//     root = buildtree();
//     bview(root);

//     return 0;
// }