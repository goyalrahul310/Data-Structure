#include<iostream>
#include "hashtable.h"
#include<cstring>
using namespace std ;
template< typename T >
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
    	while(next!=NULL)
    		delete next ;
    }
} ;

template<typename T>
class hashtable{
	private:
    Node<T>** table ;
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

    void rehash(){
    	Node<T>** oldtable = table ;
    	int oldsize = total ;
    	total = 2*total ;
    	table = new Node<T>*[total] ;
    	for(int i = 0 ; i < total ;i++){
    		table[i] = NULL ;
    	}
    	//current_size = 0 ;
    	for(int i = 0 ; i < oldsize ;i++){
    		Node<T>* temp = oldtable[i] ;
    		while(temp!= NULL){
    		insert(temp->key,temp->val) ;
    		temp = temp->next ;
    	}

    	  if(temp!=NULL)
    	  	 delete temp ;
    	}
    	delete [] oldtable ;
    }
	public:
    hashtable(int ts = 7){
    total = ts ;
    table = new Node<T>*[total] ;
    current = 0 ;
    for(int i = 0 ; i < total;i++){
    	table[i] = NULL ;
    }
	}


void insert(string key,T val){
	int idx = hash(key) ;
   Node<T>*n = new Node<T>(key,val) ;
   n->next = table[idx]; 
   table[idx] = n ;
   current++ ;
   float load_factor = current/total ;

   if(load_factor > 0.75){
   		rehash();
   }
}

T* search(string key){
	int idx = hash(key) ;
	Node<T>* temp = table[idx] ;
	while(temp != NULL){
		if(temp->key == key){
			return &temp->val ;
		}
		temp = temp->next ;
	}
	return NULL ;
}

T& operator[](string key){
	T* q = search(key) ;
	if(q == NULL){
		T garbage ;
		insert(key,garbage) ;
		q = search(key) ;
	}
	return *q ;

}
// void erase(string key){
// 	int idx = hash(key) ;
// 	Node<T>* temp = table[idx] ;
// 	while(temp != NULL){
// 		if(temp->key == key){
// 			delete temp ;
// 		}
// 		temp = temp->next ;
// 	}
// }
void print(){
	for(int i = 0 ; i < total ;i++){
		cout << "Bucket" << i << "->" ;
		Node<T>* temp = table[i] ;
		while(temp != NULL){
			cout << temp->key << "->"  ;
			temp = temp->next ;
		}
	}
}



};