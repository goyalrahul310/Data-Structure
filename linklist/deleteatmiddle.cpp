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


int length1(node* head){
	int l = 0 ;
	while(head != NULL){
		head = head->next ;
        l++ ;	
 	}
 	return l ;

}

void insertathead(node*&head,int d){
	node* n = new node(d) ;
	n->next = head ;
	head = n ;
}



void deletetail(node*&head){
	if(head == NULL) return ;

	node* t = head ;
	node* prev = NULL ;
	while(t->next != NULL){
		prev = t ;
		t = t->next ;
	}
	delete t ;
	prev->next = NULL ;
}
void deletemiddle(node*&head,int p){
	if(head==NULL||p==0){
		node*t = head ;
		head = head->next ;
		delete t ;
	}
	else if(p>=length1(head)){
		deletetail(head) ;
	}
	else{
		int j = 1 ;
		node* t = head ;
		node* prev = NULL ;
		while(j<=p-1){
			prev=t ;
			t = t->next ;
			j++ ;
		}
		prev->next = t->next ;
		delete t ;
	}


}

void print(node* head){

	while(head !=NULL){
		cout << head->data << "->" ;
		head = head->next ;
	}
}

int main(){
	node* head = NULL ;
	insertathead(head,5) ;
	insertathead(head,6) ;
	insertathead(head,7) ;
	insertathead(head,7) ;
	//deletetail(head) ;
	deletemiddle(head,2) ;
	print(head) ;
}