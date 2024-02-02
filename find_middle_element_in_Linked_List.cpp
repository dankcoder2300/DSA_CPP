//Program to find the middle element of a linked list
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
        prev=NULL;
        next=NULL;
    }

    public:
    Node(int data1,Node* prev1,Node* next1){
        data=data1;
        prev=prev1;
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
    head->prev=temp;
    head=temp;

    return head;
}

//Function to print doubly linked list
void printLL(Node* head){
    Node* ptr=head;

    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"null"<<endl;
}

// Method 1: Brute force approach
// Node* middleElement(Node* head){
//     Node* ptr=head;
//     int cnt=0;

//     while(ptr!=NULL){
//         cnt++;
//         ptr=ptr->next;
//     }
//     ptr=head;

//     for(int i=0;i<cnt/2;i++){
//         ptr=ptr->next;
//     }
//     return ptr;
// }

// Method 2: Using Tortoise-Hare Approach(Efficient appraoch)
Node* middleElement(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    Node* head= NULL;
    head= InsertAtFirst(40,head);
    head= InsertAtFirst(30,head);
    head= InsertAtFirst(20,head);
    head= InsertAtFirst(10,head);
    head= InsertAtFirst(0,head);
    cout<<"Middle element of a linked list is: ";
    head=middleElement(head);
    cout<<head->data<<endl;
    cout<<"Linked list after middle element is: "<<endl;
    printLL(head);

    return 0;
}