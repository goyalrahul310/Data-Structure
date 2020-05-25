#include<iostream>
using namespace std ;
template< typename<T> >
class Node{
public:
	string key ;
	T val ;
	Node<T>* next ;
	Node(string key1,T val1){
		key = key1 ;
		val = val1 ;
		next = NULL ;
	}

    ~Node(){
    	while(Node*next!=NULL)
    		delete next ;
    }
} ;


class hashtable{
	private:
    Node**<T> table ;
    int total ;
    int current ;
    int hash(string key){
    	int n = key.length() ;
    	int p = 1 ;
    	int idx = 0 ;

    	for(int j = 0;j<n;j++){
         idx = (idx+ (key[j]*p))%total ;
         p = p*27 ;
    	}
    	return idx ;
    }
	public:
    hashtable(int ts = 7){
    total = ts ;
    table = new Node*<T>[ts] ;
    current = 0 ;
    for(int i = 0 ; i < total;i++){
    	total[i] = NULL ;
    }
	}

} ;

void insert(string key,T val){
	int idx = hash(key) ;
   Node<T>*n = new Node(key,val) ;
   n->next = total[idx]; 
   total[idx] = n ;
   current++ ;
}

void print(){
	for(int i = 0 ; i < total ;i++){
		Node*<T> temp = table[i] ;
		while(temp != NULL){
			cout << temp->key << " " temp->val ;
			temp = temp->next ;
		}
	}
}

int main(){
	string str ;
	for(int i = 0 ; i < 20 ;i++){
		cin >> str ;
		insert(i,str);
	}
	print() ;
}