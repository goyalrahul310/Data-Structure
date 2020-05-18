#include<iostream>
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


void append(node*&head,int n){
	while(n--){
     node* t = head ;
     node* prev = NULL ;
     while(t->next != NULL){
     	prev = t ;
     	t = t->next ;
		}
		t->next = head ;
		head = t ;
		prev->next = NULL ;

	}

}

void print(node* head){
	while(head != NULL){
		cout << head->data << " " ;
		head = head->next ;
	}

}

int main(){
	int m ;
	cin >> m ;
	int d ;
	node* head = NULL;
	while(m--){
		cin >> d ;
		inserttail(head,d) ;

	}
	int k ;
	cin >> k ;
    append(head,k) ;
	print(head) ;
}