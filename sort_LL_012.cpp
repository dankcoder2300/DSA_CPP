//Program to sort singly linked list of 0's,1's and 2's
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

// Method 1: Brute Force Approach
// Node* sortLL012(Node* head)
// {
//     vector<int> arr;
//     Node* temp=head;

//     while(temp!=NULL)
//     {
//         arr.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(arr.begin(),arr.end());

//     temp=head;
//     int i=0;
//     while(i<arr.size())
//     {
//         temp->data=arr[i];
//         temp=temp->next;
//         i++;
//     }
//     return head;
// }

// Method 2: using cnt0,cnt1 and cnt2;
// Node* sortLL012(Node* head)
// {
//     int cnt0=0,cnt1=0,cnt2=0;
//     Node* temp=head;

//     while(temp!=NULL)
//     {
//         if(temp->data==0)
//         {
//             cnt0++;
//         }
//         if(temp->data==1)
//         {
//             cnt1++;
//         }
//         if(temp->data==2)
//         {
//             cnt2++;
//         }
//         temp=temp->next;
//     }

//         temp=head;
//         while(cnt0!=0)
//         {
//             temp->data=0;
//             temp=temp->next;
//             cnt0--;
//         }
//         while(cnt1!=0)
//         {
//             temp->data=1;
//             temp=temp->next;
//             cnt1--;
//         }
//         while(cnt2!=0)
//         {
//             temp->data=2;
//             temp=temp->next;
//             cnt2--;
//         }
        
//     return head;
// }

// Method 3: Optimised Solution
Node* sortLL012(Node* head)
{
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);
    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;

    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=zero=zero->next;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else
        {
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }

    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;

    Node* newHead=zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    
    return newHead;
}

int main()
{
    Node* head=NULL;
    head= InsertAtFirst(1,head);
     head= InsertAtFirst(0,head);
     head= InsertAtFirst(1,head);
     head= InsertAtFirst(2,head);
     head= InsertAtFirst(0,head);
     head= InsertAtFirst(2,head);
     head= InsertAtFirst(1,head);
    

    cout<<"Linked list before sorting 0's, 1's and 2's:";
    printLL(head);
    cout<<"Linked list after sorting 0's, 1's and 2's:";
    head=sortLL012(head);
    printLL(head);

    delete(head);

    return 0;
}