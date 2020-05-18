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
int  find(node* head1,node* head2,int n,int m){
	int d = abs(n-m) ;

	if(n>m){
		while(d--){
			head1 = head1->next ;
		}
	}
	else{
		while(d--)
			head2 = head2->next ;
	}
	
	while(head1 != NULL){
	if(head1->data == head2->data){
		return head1->data ;
	}
	head1 = head1->next ;
	head2 = head2->next ;
	}
	return -1 ;
}

int main(){
	int n,m ;
	node*head1 = NULL ;
	node*head2 = NULL ;
	cin >> n ;
	int n1 = n ; 
	int d ;
	
	while(n1--){
		cin >> d ;
		inserttail(head1,d) ;
	}
	cin >> m ;
	int m1 = m ;
	while(m1--){
		cin >> d ;
		inserttail(head2,d) ;
	}
	cout << find(head1,head2,n,m) ;
}