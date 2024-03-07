// Program to  Remove duplicates from a sorted Doubly Linked List
// Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3
// Output: Modified Linked List: 1 <-> 2 <-> 3
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

// Function to remove duplicates
Node* removeDuplicates(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        if (temp->data == temp->next->data)
        {
            Node* nextNode = temp->next->next;
            delete temp->next;
            temp->next = nextNode;
        } 
        else 
        {
            temp = temp->next;
        }
    }
    
    return head;
}

int main() {
  Node* head = NULL; // head of the LinkedList
  head = InsertatFirst(3, head);
  head = InsertatFirst(2, head);
  head = InsertatFirst(2, head);
  head = InsertatFirst(1, head);
  head = InsertatFirst(1, head);
  head = InsertatFirst(0, head);
  cout << "LinkedList before removing duplicates : " << endl;
  printLL(head);
  cout << "LinkedList after removing duplicates : " << endl;
  head=removeDuplicates(head);
  printLL(head);
  return 0;
}