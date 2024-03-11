// Program to rotate the singly linked list to the right by k places.
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
    if(head==NULL){
        head=temp;
        return head;
    }
    
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

 Node* rotateRight(Node* head, int k) {
        if(head==NULL || head->next==NULL)
        return head;

        Node* ptr=head;
        int cnt=0;
        while(ptr!=NULL)
        {
            cnt++;
            ptr=ptr->next;
        }

        k=k%cnt;
        if(k==0)
        return head;

        Node* tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }

        Node* temp1=head;
        Node* temp2=head;
        for(int i=0;i<cnt-k;i++)
        {
            temp1=temp1->next;
        }
        while(temp2->next!=temp1)
        {
            temp2=temp2->next;
        }
        tail->next=head;
        head=temp1;
        temp2->next=NULL;

        return head;
    }

  int main() {
  Node* head = NULL;
  head = InsertatFirst(5, head);
  head = InsertatFirst(4, head);
  head = InsertatFirst(3, head);
  head = InsertatFirst(2, head);
  head = InsertatFirst(1, head);
  int k;
  cout<<"Enter the value of k: ";
  cin>>k;
  cout << "LinkedList before rotating linked list by "<<k<<" positions: " << endl;
  printLL(head);
  cout << "LinkedList after rotating linked list by "<<k<<" positions: " << endl;
  head=rotateRight(head,k);
  printLL(head);
  return 0;
}