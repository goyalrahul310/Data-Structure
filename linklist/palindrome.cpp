#include <iostream>
using namespace std;
class node{
    public:
    int data ;
    node* next ;
    node* prev ;
        node(int d){
        data = d ;
        next = NULL ;
        prev = NULL ;
    }
} ;

 void inserttail(node* &head,node* &tail,int data){
        if(head == NULL){
         head = tail = new node(data)  ; 
         return ; 
     }
        
            node* t = head ;
            while(t->next != NULL){
                t= t->next ;
            }
            t->next = new node(data) ;
            tail = t->next ;
            tail->prev = t ;
            
            return ;
        
    }
 
 bool palin(node*head,node*tail){
  	while(head != tail && tail->next != head && head->prev != tail){
  		if(head->data != tail->data)
  			return false ;

  		head = head->next ;
  		tail = tail->prev ;
  	}
  	return true ;

  }

int main(){
	int n,m ;
	node*head = NULL ;

	node*tail = NULL ;
	cin >> n ;
	int d ;
	
	while(n--){
		cin >> d ;
		inserttail(head,tail,d) ;
	}
	
	if(palin(head,tail)) cout << "True" ;
	else cout << "False" ;
}