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


node* find(node* head,int k){
    if(head == NULL || head->next == NULL)
        return head ;
    node* t = head ;
    while(k--){
        t = t->next ;
    }
    node*t2 = head ;
    while(t!=NULL){
        t= t->next ;
        t2 = t2->next ;
    }
    return t2 ;
}


void print(node*head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }
}


int main(){
    int n,d ;
    cin >> n ;
    node* head = NULL ;
    while(n--){
        cin >> d ;
        inserttail(head,d) ;
    }
    int k ;
    cin >> k ;
    node*t = find(head,k) ;

    cout << t->data ;

}