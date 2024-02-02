//Program to delete node at end of a linked list
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
        prev=nullptr;
        next=nullptr;
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

//Function to delete node at end of a doubly linked list
Node* deleteAtLast(Node* head)
{
    if(head==NULL)
    {
        return head;
    }
    
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }

    Node* ptr=head;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    Node* prev=ptr->prev;
    prev->next=NULL;
    ptr->prev=NULL;
    free(ptr);

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
  cout << "LinkedList before deleting 40 at end : " << endl;
  printLL(head);
  cout << "LinkedList after deleting 40 at end : " << endl;
  head=deleteAtLast(head);
  printLL(head);
  return 0;
}