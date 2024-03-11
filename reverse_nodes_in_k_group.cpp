// Program to reverse the nodes of the list k at a time, and return the modified list.
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

Node* reverseLL(Node* head)
    {
        Node* temp=head;
        Node* prev=NULL;

        while(temp!=NULL)
        {
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    Node* findKthNode(Node* temp,int k)
    {
        k--;
        while(temp!=NULL && k!=0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }

    Node* reverseKGroup(Node* head, int k) {
        Node* temp=head;
        Node* prevNode=NULL;
       while(temp!=NULL)
       {
           Node* kthNode=findKthNode(temp,k);
           if(kthNode==NULL)
           {
               if(prevNode)
               prevNode->next=temp;

               break;
           }
           Node* nextNode=kthNode->next;
           kthNode->next=NULL;
           reverseLL(temp);
           if(temp==head)
           head=kthNode;
           else
           {
               prevNode->next=kthNode;
           }
           prevNode=temp;
           temp=nextNode;
       }
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
  cout << "LinkedList before reversing group of "<<k<<" nodes: " << endl;
  printLL(head);
  cout << "LinkedList after reversing group of "<<k<<" nodes: " << endl;
  head=reverseKGroup(head,k);
  printLL(head);
  return 0;
}