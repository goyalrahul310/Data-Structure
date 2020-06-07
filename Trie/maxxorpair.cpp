#include<iostream>
#include<cmath>
using namespace std ;




class trie{
public:
	trie* left ;
	trie* right ;
} ;


void insert(trie* head,int d){
	trie* curr = head ;
	for(int i = 31 ; i>=0 ;i--){
		int bit = (d>>i)&1 ;
		if(bit == 0){
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

int maxxorpair(trie* &head,int el){
	trie* curr = head ;
	int maxi = 0 ;
	for(int i = 31 ;i >= 0 ;i--){
		int bit = (el>>i)&1 ;
		if(bit == 0){
			if(curr->right != NULL){
				curr = curr->right ;
                maxi+=pow(2,i) ;
			}
			else{
				curr = curr->left ;
			}
		}
		else{
			if(curr->left != NULL){
				curr = curr->left ;
				maxi +=pow(2,i) ;
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
  int maxv = 0 ;
  trie* head = new trie() ;
  for(int i= 0 ; i<n;i++){
  	cin >> a[i] ;
  	insert(head,a[i]) ;
  	
  }
  
   for(int i = 0 ; i<n;i++){
  	int m = maxxorpair(head,a[i]) ;
  	maxv = max(m,maxv) ;
   }
  cout << maxv << " "  ;



}