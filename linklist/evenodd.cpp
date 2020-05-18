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


node* arrange(node* head){
    if(head == NULL || head->next == NULL)
        return head ;
    node* even = NULL ;
    node* odd = NULL ;
    while(head != NULL){
        if(head->data % 2 == 0){
            inserttail(even,head->data) ;
        }
        else{
            inserttail(odd,head->data) ;
        }
        head = head->next ;
    }

    if(even == NULL) return odd ;
    else if(odd == NULL) return even ;

    else{
        node* t = odd ;
        while(t->next != NULL){
            t = t->next ;
        }
        t->next = even ;
    }
    return odd ;
}
void print(node* head){
    while(head!= NULL){
        cout << head->data << " " ;

        head = head->next ;
    }
}


int main(){
    int n ;

    node* head = NULL ;
    cin >> n ;
    int data ;
    while(n--){
        cin >> data ;
        inserttail(head,data) ;
    }
    node* h = arrange(head) ;

    print(h) ;
}