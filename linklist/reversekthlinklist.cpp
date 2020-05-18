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
node* rev(node* &head,int k){
	  int x = k ;
		node* prev = NULL ;
		node* curr = head ;
		node* n = NULL;
		int count = 0;
		while(count < x && curr!=NULL){
		n = curr->next ;
		curr->next = prev ;
		prev = curr ;
		curr = n ;
		x--  ;
	}
		if(n!=NULL){
			head->next = rev(n,k) ;
			
		}
		return prev;
}

void print(node* head){

	while(head!=NULL){
		cout << head->data << " ";
		head = head->next ;
	}
}
int main(){
	int n,k,data;
	node* head = NULL ;
	cin >> n >> k ;
	while(n--){
		cin >> data ;
		inserttail( head,data) ;
	}
	node * p  = rev(head,k) ;
	print(p) ;
}