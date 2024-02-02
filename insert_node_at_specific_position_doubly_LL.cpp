//Program to insert node at specific position of a doubly linked list
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

//Function to print Linked List
void printLL(Node* head)
{
    Node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"null"<<endl;
}

//Function to insert node at specific position of doubly linked list
Node* insertAtSpecificPosition(int data,Node* head,int pos)
{
    Node* temp= new Node(data);

    //if linked list is empty
    if(head==NULL)
    {
        temp=head;
        return head;
    }
    //if we want to insert at position 1
    if(pos==1){
        temp->next=head;
        head->prev=temp;
        head=temp;
        return head;
    }

    //if we want to insert after position 1
    Node* ptr=head;
    int i=1;
    while(i<pos-1 && ptr!=NULL){
        ptr=ptr->next;
        i++;
    }

    //if we want to insert at last position
    if(ptr->next==NULL){
        ptr->next=temp;
        temp->prev=ptr;
        temp->next=NULL;
        return head;
    }

    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next=temp;

    return head;
}

int main() {
  Node* head = NULL;
  head = InsertatFirst(40, head);
  head = InsertatFirst(30, head);
  head = InsertatFirst(20, head);
  head = InsertatFirst(10, head);
  head = InsertatFirst(0, head);
  cout << "LinkedList before inserting 50 before 0 : " << endl;
  printLL(head);
  cout << "LinkedList after inserting 50 before 0 : " << endl;
  head=insertAtSpecificPosition(50,head,1);
  printLL(head);
  return 0;
}