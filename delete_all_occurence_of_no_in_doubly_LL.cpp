// Program to Delete all occurrences of a given key in a doubly linked list
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

//Function to insert node at beginning of a doubly linked list
Node* insertAtBeginning(Node* head,int data)
{
    Node* temp=new Node(data);

    if(head==NULL){
        head=temp;
        return head;
    }   
    temp->next=head;
    head->prev=temp;
    head=temp;
    
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

Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==k)
        {
            if(temp==head)
            {
                head=head->next;
            }
            Node* prevNode=temp->prev;
            Node* nextNode=temp->next;

            if(prevNode)
            prevNode->next=nextNode;
            if(nextNode)
            nextNode->prev=prevNode;

            free(temp);
            temp=nextNode;
        }
        else
        temp=temp->next;
    }
    return head;
}

int main() {
  Node* head = NULL;
  head = InsertatFirst(10, head);
  head = InsertatFirst(6, head);
  head = InsertatFirst(10, head);
  head = InsertatFirst(10, head);
  head = InsertatFirst(4, head);
  head = InsertatFirst(10, head);
  cout << "LinkedList before deleting all occurences of 10 : " << endl;
  printLL(head);
  cout << "LinkedList after deleting all occurences of 10 : " << endl;
  head=deleteAllOccurrences(head,10);
  printLL(head);
  return 0;
}