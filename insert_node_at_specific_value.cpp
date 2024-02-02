//Program to insert node at specific value of a linked list
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

//Function to insert node at the specific value of a linked list
Node* insertAtValue(int data,Node* head,int val)
{
    Node* temp= new Node(data);

    if(head==NULL){
        head=temp;
        
        return head;
    }

    // if we want to insert at position 1
   if(head->data==val){
    temp->next=head;
    head=temp;

    return head;
   }

    Node* ptr=head;
    
   //if we want to insert node after position 1
   while(ptr->next!=NULL){
    if(ptr->next->data==val){
        break;
    }
    ptr=ptr->next;
   }
   temp->next=ptr->next;
   ptr->next=temp;

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
  cout << "LinkedList before inserting node of value 50 : " << endl;
  printLL(head);
  head= insertAtValue(50,head,40);
  cout << "LinkedList after inserting node of value 50 : " << endl;
  printLL(head);
  return 0;
}