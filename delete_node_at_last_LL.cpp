//Program to delete node at beginning of a lonked list
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
Node* Insert(int data,Node* head)
{
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;

    return head;
}

//Function to delete node at the last of a linked list
Node* deleteAtLast(Node* head)
{
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        free(head);
        return NULL;
    }
    
   Node* temp=head;
   while(temp->next->next!=NULL){
        temp=temp->next;
   }
   
   free(temp->next);
   temp->next=NULL;

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

int main() {
  Node* head = NULL; // head of the LinkedList
  head = Insert(40, head);
  head = Insert(30, head);
  head = Insert(20, head);
  head = Insert(10, head);
  head = Insert(0, head);
  cout << "LinkedList before deleting 40 at end : " << endl;
  printLL(head);
  head= deleteAtLast(head);
  cout << "LinkedList after deleting 40 at end : " << endl;
  printLL(head);
  return 0;
}