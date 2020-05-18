#include<iostream>
using namespace std ;
class node{

public:
	int data ;
	node* next ;
	node(int d){
		data = d ;
		next = NULL ;
	}
} ;




void insertathead(node*&head,int d){
	node* n = new node(d) ;
	n->next = head ;
	head = n ;
}



void print(node* head){

	while(head !=NULL){
		cout << head->data << "->" ;
		head = head->next ;
	}
}

node* midpt(node* head){
	node*f = head->next ;
	node*s = head ;
	while(f !=NULL && f->next != NULL){
		s = s->next ;
		f = f->next;
		if(f!=NULL)
			f  = f->next ;
	}
	return s ;
}
node* merge(node*&a,node*&b){
	if(a==NULL) return b ;
	else if(b==NULL) return a ;

    node* c ;
    if(a->data < b->data){
    	c = a ;
    	c->next = merge(a->next,b) ;
    }
    else{
    	c=b ;
    	c->next = merge(a,b->next) ;
    }

    return c ;


}
void mergesort(node* &head){
	if(head == NULL || head->next == NULL)
		return  ;


	node* mid = midpt(head) ;
	node* a = head ;
	node* b = mid->next ;
	mid->next = NULL ;
	mergesort(a) ;
	mergesort(b) ;


	head = merge(a,b) ;
    return ;

}

int main(){
	node* head = NULL ;
	insertathead(head,5) ;
	insertathead(head,6) ;
	insertathead(head,7) ;
	insertathead(head,7) ;
	mergesort(head) ;
	print(head) ;
}