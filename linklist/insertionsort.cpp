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

void segregate(node *&head)
{
  node *current_ptr=head;
  node *insert_ptr=head;
  current_ptr=head->next;
  while(current_ptr!=NULL)
  {
    insert_ptr=head;
    while(insert_ptr!=current_ptr)
    {
      if(insert_ptr->data >= current_ptr->data)
      {
        int temp=current_ptr->data;
        current_ptr->data=insert_ptr->data;
        insert_ptr->data=temp;
      }
      else
      {
        insert_ptr=insert_ptr->next;
      }
    }
    current_ptr=current_ptr->next;
  }
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
   


}