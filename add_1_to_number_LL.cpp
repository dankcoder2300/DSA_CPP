//Program to add 1 to the number represented by a linked list
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

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

//Function to insert node at beginning of linked list
Node* InsertAtFirst(int data,Node* head){
    Node* temp=new Node(data);

    if(head==NULL){
        head=temp;
        return head;
    }

    temp->next=head;
    head=temp;

    return head;
}

//Function to print singly linked list
void printLL(Node* head){
    Node* ptr=head;

    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"null"<<endl;
}

//Function to reverse the linked list
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

// Method 1: Reversing the linked list and adding 1 to it and then reversing linked list again
// Node* addOneToLL(Node* head)
// {
//     head=reverseLL(head);
//     Node* temp=head;
//     int carry=1;
    

//     while(temp!=NULL)
//     {
//         temp->data=temp->data+carry;

//         if(temp->data<10)
//         {
//             carry=0;
//             break;
//         }
//         else
//         {
//             temp->data=0;
//             carry=1;
//         }
//         temp=temp->next;
//     }

//     if(carry==1)
//     {
//         Node* newNode=new Node(1);
//         head=reverseLL(head);
//         newNode->next=head;

//         return newNode;
//     }
//     head=reverseLL(head);

//     return head;
// }

//Method 2: Using recursive approach
int addHelper(Node* temp)
{
    if(temp==NULL)
    return 1;

    int carry=addHelper(temp->next);

    temp->data+=carry;

    if(temp->data<10)
    return 0;

    temp->data=0;
    return 1;
}

Node* addOneToLL(Node* head)
{
    int carry=addHelper(head);
    if(carry==1)
    {
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
} 

int main()
{
    Node* head=NULL;
    head= InsertAtFirst(9,head);
    head= InsertAtFirst(9,head);
    
    cout<<"Linked list before adding 1: ";
    printLL(head);
    cout<<"Linked list after adding 1: ";
    head=addOneToLL(head);
    printLL(head);

    delete(head);

    return 0;
}