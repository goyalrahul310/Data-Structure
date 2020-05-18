#include<iostream>
#include<queue>
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
};


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

void printpre(node* root){
	if(root == NULL){
		return ;
	}
	cout << root->data << " " ;
	printpre(root->left) ;
	printpre(root->right) ;

}

void printin(node* root){
	if(root == NULL) return ;
	printin(root->left) ;
	cout << root->data << " " ;
	printin(root->right) ;
}

void printpost(node* root){
	if(root == NULL) return ;
	printpost(root->left) ;
	printpost(root->right) ;
	cout << root->data << " " ; 
}

int height(node* root){
   
   if(root == NULL) return 0 ;

   int ls = height(root->left) ;
   int rs = height(root->right) ;

   return max(ls,rs) +1 ;
}
void printklevel(node* root,int k){
	if(root == NULL) return ;
	if(k==1){
		cout << root->data << " " ;
		return ;
	}

	printklevel(root->left,k-1) ;

	printklevel(root->right,k-1) ;
 }

 void printalllevel(node* root){
 	int h = height(root) ;
 	for(int i = 1 ; i <= h ;i++){
 		printklevel(root,i) ;
 	}
 }


 void bfs(node* root){
 	queue<node*> q ;
 	q.push(root) ;
 	q.push(NULL) ;

 	while(!q.empty()){
 		node* f = q.front() ;
 		if(f == NULL){
 			cout << endl ;
 			q.pop() ;
 			if(!q.empty()){
 				q.push(NULL) ;
 			}
 		}
 		else{
 			cout << f->data << " " ;
 			q.pop() ;
 			if(f->left){
 				q.push(f->left) ;
 			}
 			if(f->right){
 				q.push(f->right) ;
 			}
 		}
 	}

 }


 int count(node* root){
 	if(root ==NULL) return 0;
 	return 1 + count(root->left) + count(root->right) ;
 }

 int sumroot(node* root){
 	if(root == NULL) return 0 ;
 	return root->data + sumroot(root->left) + sumroot(root->right) ;
 } 


int diameter(node* root){
	if(root == NULL) return 0 ;

	int h1 = height(root->left) ;
	int h2 = height(root->right) ;

	int op1 = h1+ h2 ;
	int op2 = diameter(root->left) ;
	int op3 = diameter(root->right) ;
	return max(op1,max(op2,op3)) ;
}

class pair1{
public:
	int height1 ;
	int diameter1 ;
};
pair1 optimiseddiameter(node* root){
	pair1 p ;
	if(root == NULL){
		p.height1 = p.diameter1  = 0 ;
		return p ;
	}
    pair1 left = optimiseddiameter(root->left) ;
    pair1 right = optimiseddiameter(root->right) ;
	 p.height1 = max(left.height1,right.height1) + 1 ;
	 p.diameter1 = max(left.height1+right.height1,max(left.diameter1,right.diameter1)) ;
	return p ;
}


class HBpair{
public:
	int height ;
	bool balance ;
} ;

HBpair isbalanced(node* root){
	HBpair p ;
	if(root == NULL) {
		p.height = 0 ;
		p.balance = true ;
		return p;
	}

	HBpair left = isbalanced(root->left) ;
	HBpair right = isbalanced(root->right) ;
    p.height = max(left.height,right.height) + 1 ;
	if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
		p.balance = true ;
	} 
	else{
		p.balance = false ;
	}
	return p ;
}



node* buildbalanced(int a[],int s,int e){
	if(s>e) return NULL ;

	int mid  = (s+e)/2 ;
	node* root = new node(a[mid]) ;

	root->left = buildbalanced(a,s,mid-1) ;
	root->right = buildbalanced(a,mid+1,e) ;
	return root ;
}


node* buildprein(int pre[],int in[],int s,int e){
 	if(s>e) return NULL ;
 	static int i = 0 ;
 	node* root = new node(pre[i]) ;
    
    int index = -1 ;
    for(int j = s;j<=e;j++){
    	if(pre[i] == in[j]){
    		index = j ;
    	}
    }
 	i++ ;

 	root->left = buildprein(pre,in,s,index-1) ;
 	root->right = buildprein(pre,in,index+1,e) ;
 	return root ;


 }
int max_level = -1 ;
vector<int> v ;
void rightview(node* root,int level){
	if(root == NULL) return ;
	if(level > max_level)
		{
			v.push_back(root->data) ;
		    max_level = level ;
		 }
	rightview(root->right,level+1) ; 
	rightview(root->left,level+1) ;
	return ; 
}





int main(){
	node* root = buildtree() ;
	cout << "PRE ORDER : " ;
	printpre(root) ;
	cout << endl ;
    cout  << "INORDER : " ;
	printin(root) ;
	cout << endl ;
	cout << "POSTORDER : " ;
	printpost(root) ;
	cout << endl ;
	cout << "LEVEL ORDER : " ;
	printalllevel(root) ;
	cout << endl ;
	cout << "LEVEL ORDER BFS : " ;
	bfs(root) ;
	cout << endl ;
	cout << "count : " ;
	cout << count(root) ;
	cout << endl ;
	cout << "sum : " ;
	cout << sumroot(root) ;
	cout << "Diameter :" ;
	cout << diameter(root) ;
	cout << endl << "optimiseddiameter and height" ;
	pair1 l = optimiseddiameter(root) ;
	cout << l.height1 << l.diameter1 ;
    cout << endl ;
	if(isbalanced(root).balance){
		cout << "balance" ;
	}
	else{
		cout << "Not balance" ;
	}

   cout << "build balanced tree : " ;
   int a[] = {1,2,3,4,5,6,7} ;
   int n = sizeof(a)/sizeof(int) ;
   node* r = buildbalanced(a,0,n-1) ;
   bfs(r) ;
  int pre[] = {1,2,3,4,8,5,6,7} ;
   int in[] = {3,2,8,4,1,6,7,5} ;
   node* rt = buildprein(pre,in,0,7) ;
   bfs(rt) ;
   rightview(root,0) ;
   for(auto i:v) {
   	cout << i  ; 
   }


}




















