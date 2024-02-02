//Program to delete node at specific position of a linked list
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

//Function to delete node at the specific position of a linked list
Node* deleteAtPositiont(Node* head,int pos)
{
    if(head==NULL){
        return NULL;
    }

    Node* temp= head;
    // if we want to delete at position 1
    if(pos==1){
        head=temp->next;
        free(temp);
        return head;
    }
    
   //if we want to delete node after position 1
   int i=1;
   while(i<pos-1 && temp!=NULL){
    temp=temp->next;
    i++;
   }

   if(temp==NULL || temp->next==NULL)
   return head;

   Node* prev= temp->next;
   temp->next=temp->next->next;
   free(prev);

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
  cout << "LinkedList before deleting node at position 3 : " << endl;
  printLL(head);
  head= deleteAtPositiont(head,3);
  cout << "LinkedList after deleting node at position 3 : " << endl;
  printLL(head);
  return 0;
}