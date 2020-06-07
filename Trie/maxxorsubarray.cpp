#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std ;

class trie{
public:
	trie* left ;
	trie* right ;
} ;



void ele(vector<int> &element,int *a,int n){
	
	int x = a[0];
	element.push_back(a[0]) ;
	for(int i = 1 ; i < n; i++){
		  x ^= a[i] ;
		  element.push_back(x) ;

	}

}

void insert(trie* head,int d){
	trie* curr = head ;
	for(int i = 31;i>>=0;i--){
		int bit = (d>>i)&1 ;
		if(bit==0){
			if(curr->left == NULL){
				curr->left = new trie() ;
			}
			curr = curr->left ;
		}
		else{
			if(curr->right == NULL){
				curr->right = new trie() ;
			}
			curr = curr->right ;
		}
	}
}

int maxsubarray(trie*head,int ele){
	trie* curr = head ;
	int maxi = 0 ;
	for(int i =31;i>=0;i--){
		int bit = (ele>>i)&1;
		if(bit == 0){
			if(curr->right != NULL){
				curr = curr->right ;
				maxi += pow(2,i) ; 
			}
			else{
				curr = curr->left ;
			}
		}
		else{
			if(curr->left != NULL){
				curr = curr->left ;
				maxi += pow(2,i) ;
			}
			else{
				curr = curr->right ;
			}
		}
	}

	return maxi ;
}


int main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i<n;i++){
		cin >> a[i] ;
	}
	vector<int> v ;
	trie* head = new trie() ;
	ele(v,a,n) ;
    for(int i = 0 ; i<v.size();i++){
    	insert(head,v[i]) ;
    }
    int maxv = 0 ;
    for(int i = 0 ; i<n;i++){
    	int m = maxsubarray(head,v[i]) ;
    	maxv = max(m,maxv) ;
    }
	cout << maxv ;
}

