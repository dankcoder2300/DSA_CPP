//Program to merge two sorted singly linked list
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

// Function to convert array into linked list
Node* convertArrayToLL(vector<int> vec)
{
    Node* head= new Node(vec[0]);
    Node* ptr=head;
    for(int i=1;i<vec.size();i++)
    {
        Node* temp=new Node(vec[i]);
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}

// Method 1: Using extra vector (Brute force approach)
// Node* mergeLL(Node* head1,Node* head2){
//     vector<int> vec;

//     Node* temp=head1;
//     while(temp!=NULL)
//     {
//         vec.push_back(temp->data);
//         temp=temp->next;
//     }
//     temp=head2;
//     while(temp!=NULL)
//     {
//         vec.push_back(temp->data);
//         temp=temp->next;
//     }
    
//     sort(vec.begin(),vec.end());

//     Node* head=convertArrayToLL(vec);
    
//     return head;
// }

// Method 2: using two pointers approach
Node* mergeLL(Node* head1,Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dNode=new Node(-1);
    Node* temp=dNode;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data <= temp2->data)
        {
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }

    if(temp1)
    temp->next=temp1;
    
    if(temp2)
    temp->next=temp2;

    return dNode->next;
}


int main()
{
    Node* head1= NULL;
    Node* head2= NULL;
    head1= InsertAtFirst(80,head1);
    head1= InsertAtFirst(60,head1);
    head1= InsertAtFirst(40,head1);
    head1= InsertAtFirst(20,head1);
    head1= InsertAtFirst(0,head1);
    head2= InsertAtFirst(90,head2);
    head2= InsertAtFirst(70,head2);
    head2= InsertAtFirst(50,head2);
    head2= InsertAtFirst(30,head2);
    head2= InsertAtFirst(10,head2);
    cout<<"Linked List 1 before sorting: "<<endl;
    printLL(head1);
    cout<<"Linked List 2 before sorting: "<<endl;
    printLL(head2);
    cout<<"Linked list after merging two sorted linked list is: "<<endl;
    Node* head=mergeLL(head1,head2);
    printLL(head);

    return 0;
}