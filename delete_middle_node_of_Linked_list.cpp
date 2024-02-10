//Program to delete the middle node  of a linked list
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
// Node* deleteMiddleNode(Node* head){
//     Node* temp=head;
//     int cnt=0;

//     while(temp!=NULL)
//     {
//         cnt++;
//         temp=temp->next;
//     }
//     int val=cnt/2;
    
//     //we have to move val position after head
//     temp=head;
//     for(int i=1;i<val;i++)
//     {
//         temp=temp->next;
//     }

//     Node* delNode=temp->next;
//     temp->next=temp->next->next;
//     free(delNode);

//     return head;
// }

// Method 2: Efficient Method
// Node* deleteMiddleNode(Node* head)
// {
//     if(head==NULL || head->next==NULL)
//     return NULL;

//     Node* slow=head;
//     Node* fast=head;

//     while(fast!=NULL && fast->next!=NULL)
//     {
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     Node* temp=head;
//     while(temp->next!=slow)
//     {
//         temp=temp->next;
//     }

//     Node* delNode=temp->next;
//     temp->next=temp->next->next;
//     free(delNode);

//     return head;
// }

// Method 3: Using Modified Tortoise-Hare Approach(Efficient appraoch)
Node* deleteMiddleNode(Node* head){
    Node* slow=head;
    Node* fast=head;

    if(head==NULL || head->next==NULL)
    return NULL;

    //skipping first step of moving slow pointer as to stop slow pointer just before middle node
    fast=fast->next->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* delNode=slow->next;
    slow->next=slow->next->next;
    free(delNode);

    return head;
}

int main()
{
    Node* head= NULL;
    head= InsertAtFirst(40,head);
    head= InsertAtFirst(30,head);
    head= InsertAtFirst(20,head);
    head= InsertAtFirst(10,head);
    head= InsertAtFirst(0,head);
    cout<<"Linked List before deleting middle node: "<<endl;
    printLL(head);
    cout<<"Linked list after deleting middle node is: "<<endl;
    head=deleteMiddleNode(head);
    printLL(head);

    return 0;
}