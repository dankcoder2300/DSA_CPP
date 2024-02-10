//Program to sort the singly linked list
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

// Method 1: Using extra vector (Brute force approach)
// Node* SortLL(Node* head){
//     vector<int> vec;

//     Node* temp=head;
//     while(temp!=NULL)
//     {
//         vec.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(vec.begin(),vec.end());

//     temp=head;
//     int i=0;
//     while(i<vec.size())
//     {
//         temp->data=vec[i];
//         i++;
//         temp=temp->next;
//     }

//     return head;
// }


// Method 2: Using Modified Tortoise-Hare Approach and merge sort approach(Efficient appraoch)
Node* findMiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head->next;  //so as to point slow pointer 1st middle in case of even length linked list

    while(fast!=NULL && fast->next!= NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

Node* mergeTwoSortedLL(Node* head1,Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dNode= new Node(-1);
    Node* temp=dNode;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<=temp2->data)
        {
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else
        {
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }

        if(temp1)
        temp->next=temp1;

        if(temp2)
        temp->next=temp2;

    }
    
    return dNode->next;
}

Node* SortLL(Node* head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node* middleNode=findMiddle(head);
    Node* leftHead=head;
    Node* rightHead=middleNode->next;
    middleNode->next=NULL;

    leftHead=SortLL(leftHead);
    rightHead=SortLL(rightHead);

    return mergeTwoSortedLL(leftHead,rightHead);        //we use return because it return new head
}

int main()
{
    Node* head= NULL;
    head= InsertAtFirst(30,head);
    head= InsertAtFirst(10,head);
    head= InsertAtFirst(40,head);
    head= InsertAtFirst(20,head);
    head= InsertAtFirst(0,head);
    cout<<"Linked List before sorting: "<<endl;
    printLL(head);
    cout<<"Linked list after sorting is: "<<endl;
    head=SortLL(head);
    printLL(head);

    return 0;
}