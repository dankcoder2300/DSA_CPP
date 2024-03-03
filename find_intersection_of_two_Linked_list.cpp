//Program to find the intersection of two singly linked list
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
// Node* findIntersection(Node* head1,Node* head2)
// {
//     if(head1==NULL || head2==NULL)
//     return NULL;

//     while(head1!=NULL)
//     {
//         Node* temp=head2;
//         while(temp!=NULL)
//         {
//             if(temp==head1)
//             return head1;

//             temp=temp->next;
//         }
//         head1=head1->next;
//     }

//     return NULL;
// }

// Method 2: Using set for storing linked list
// Node* findIntersection(Node* head1,Node* head2)
// {
//     Node* temp=head1;
//     unordered_set<Node*> st;
//     while(temp!=NULL)
//     {
//         st.insert(temp);
//         temp=temp->next;
//     }
//     temp=head2;
//     while(temp!=NULL)
//     {
//         if(st.find(temp)!=st.end())
//         return temp;

//         temp=temp->next;
//     }

//     return NULL;
// }

// Method 3: Using differnce in length method
// int getDifference(Node* head1,Node* head2)
// {
//     int cnt1=0,cnt2=0;
//     Node* temp=head1;
//     while(temp!=NULL)
//     {
//         cnt1++;
//         temp=temp->next;
//     }
//     temp=head2;
//     while(temp!=NULL)
//     {
//         cnt2++;
//         temp=temp->next;
//     }

//     return cnt1-cnt2;
// }

// Node* findIntersection(Node* head1,Node* head2)
// {
//     int diff=getDifference(head1,head2);
//     if(diff<0)
//     {
//         while(diff++!=0)
//         head2=head2->next;
//     }
//     else
//     while(diff--!=0)
//     head1=head1->next;

//     while(head1!=NULL)
//     {
//         if(head1==head2)
//         return head1;

//         head1=head1->next;
//         head2=head2->next;
//     }

//     return NULL;
// }

// Method 4: Optimised Solution
Node* findIntersection(Node* head1,Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=temp2)
    {
        temp1=temp1==NULL?head2:temp1->next;
        temp2=temp2==NULL?head1:temp2->next;
    }
    return temp1;
}

int main()
{
    Node* head1= NULL;
    Node* head2= NULL;
    head1= InsertAtFirst(2,head1);
    head1= InsertAtFirst(6,head1);
    head1= InsertAtFirst(4,head1);
    head1= InsertAtFirst(1,head1);
    head1= InsertAtFirst(3,head1);
    cout<<"Linked List 1: "<<endl;
    printLL(head1);
    head2= InsertAtFirst(2,head2);
    head2= InsertAtFirst(6,head2);
    head2= InsertAtFirst(4,head2);
    head2= InsertAtFirst(5,head2);
    head2= InsertAtFirst(4,head2);
    head2= InsertAtFirst(2,head2);
    head2= InsertAtFirst(1,head2);
    cout<<"Linked List 2: "<<endl;
    printLL(head2);
    Node* ans=findIntersection(head1,head2);
    if(ans==NULL)
    {
        cout<<"No Intersection between two linked lists"<<endl;
    }
    else{
        cout<<"Linked lists intersects at node: "<<ans->data<<endl;
    }

    return 0;
}