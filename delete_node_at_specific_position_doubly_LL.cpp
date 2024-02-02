//Program to delete node at specific position of a doubly linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data1){
        data=data1;
        prev=NULL;
        next=NULL;
    
    }

    public:
    Node(int data1,Node* prev1,Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};

//Function to insert node at the beginning of a doubly linked list
Node* InsertatFirst(int data,Node* head)
{
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    
    temp->next=head;
    temp->prev=nullptr;
    head->prev=temp;
    head=temp;

    return head;
}

//Function to delete node at the specific position of a doubly linked list
Node* deleteAtPosition(Node* head,int pos)
{
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        free(head);
        return NULL;
    }
    
    Node* ptr= head;
    // if we want to delete at position 1
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        ptr->next=NULL;
        free(ptr);

        return head;
    }
    
   //if we want to delete node after position 1
   int i=1;
   while(i<=pos-1 && ptr!=NULL){
    ptr=ptr->next;
    i++;
   }

   if(ptr->next==NULL)
   {
    ptr->prev->next=NULL;
    ptr->next=NULL;
    free(ptr);
    return head;
   }

   ptr->prev->next=ptr->next;
   ptr->next->prev=ptr->prev;

    return head;
}

//Function to print doubly Linked List
void printLL(Node* head)
{
    Node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"null"<<endl;
}

int main() {
  Node* head = NULL; 
  head = InsertatFirst(40, head);
  head = InsertatFirst(30, head);
  head = InsertatFirst(20, head);
  head = InsertatFirst(10, head);
  head = InsertatFirst(0, head);
  cout << "LinkedList before deleting node at position 3 : " << endl;
  printLL(head);
  head= deleteAtPosition(head,5);
  cout << "LinkedList after deleting node at position 3 : " << endl;
  printLL(head);
  return 0;
}