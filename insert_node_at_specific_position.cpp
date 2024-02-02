//Program to insert node at specific position of a linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data=data1;
        next=NULL;
    }
};

//Function to insert node at the beginning of a linked list
Node* InsertatFirst(int data,Node* head)
{
    Node* temp=new Node(data);
    temp->next=head;
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

//Function to insert node at specific position of a linked list
Node* insertAtPosition(int data,Node* head,int pos){
    Node* temp= new Node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    
    if(pos==1){
        temp->next=head;
        head=temp;

        return head;
    }

    Node* ptr=head;
    int i=1;
    while(i<pos-1){
        ptr=ptr->next;
        i++;
    }
    temp->next=ptr->next;
    ptr->next=temp;

    return head;
}
int main() {
  Node* head = NULL; // head of the LinkedList
  head = InsertatFirst(40, head);
  head = InsertatFirst(30, head);
  head = InsertatFirst(20, head);
  head = InsertatFirst(10, head);
  head = InsertatFirst(0, head);
  cout << "LinkedList before inserting 50 at end : " << endl;
  printLL(head);
  head= insertAtPosition(50,head,6);
  cout << "LinkedList after inserting 50 at end : " << endl;
  printLL(head);
  return 0;
}