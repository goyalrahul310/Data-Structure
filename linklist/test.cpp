#include <iostream>
using namespace std;
class node{
    public:
    int data ;
    node* next ;
    node(int d){
        data = d ;
        next = NULL ;
    }
} ;

 void inserttail(node* &head,int data){
        if(head == NULL){ head = new node(data)  ; return ; }
        
            node* tail = head ;
            while(tail->next != NULL){
                tail = tail->next ;
            }
            tail->next = new node(data) ;
            return ;
        
    }



node* merge(node* a,node* b){
	if(a == NULL) return b ;
	else if(b== NULL) return a ;


    node* c ;
	if(a->data < b->data){
		c =  a; 
		c->next = merge(a->next,b) ;
	}
	else{
		c = b ;
		c->next = merge(a,b->next) ; 
	}
	return c ;
}
void print(node* head){

	while(head!=NULL){
		cout << head->data << " ";
		head = head->next ;
	}
}
int main(){
	int n1 ;
	node* head1 = NULL ;
	cin >> n1 ;
	int data ;
	while(n1--){
		cin >> data ;
		inserttail( head1,data) ;
	}
	int n2 ;
	cin >> n2 ;
	node* head2 = NULL ;
	while(n2--){
		cin >> data ;
		inserttail(head2,data) ;
	}
	node*m = merge(head1,head2) ;
	print(m) ;
	
}