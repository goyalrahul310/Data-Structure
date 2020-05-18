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

 int inserttail(node* &head,int data){
    int f = 0 ;
        if(head == NULL){ 
            head = new node(data)  ;
           // head->next = head ;
         return 1; 
     }
            node* n = new node(data) ;
            node* tail = head ;
            while(tail->next != NULL){
                if(n->data == tail->data){
                    f==1;
                    return 0 ;
                }
                tail = tail->next ;
            }
            //if(f==1){
              //  return 0 ;
            //}


            tail->next = n ;
            //tail = tail->next ;

            return 1;
        
    }


    void print(node*head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }
}



    int main(){
        int n,d;
        node* head = NULL ;
        int r = 1 ;
        cin >> d ;
        while(d != -1 && r==1){
            r = inserttail(head,d) ;
            cin >> d ;
            //r = inserttail(head,d) ;
        }
       print(head) ;
    }


