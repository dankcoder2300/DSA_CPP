//Program to reverse a doubly linked list
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

// method 1: using stack(brute force approach)
// Node* reverseLL(Node* head){
//     stack<int> st;
//     Node* ptr=head;

//     while(ptr!=NULL){
//         st.push(ptr->data);
//         ptr=ptr->next;
//     }

//     ptr=head;

//     while(st.size()){
//         ptr->data=st.top();
//         st.pop();
//         ptr=ptr->next;
//     }

//     return head;
// }

// Method 2: using two pointers and single traversal(efficient approach)
// Node* reverseLL(Node* head){
//     if(head==NULL || head->next==NULL)
//     return head;

//     Node* back=NULL;
//     Node* curr=head;

//     while(curr!=NULL){
//         back=curr->prev;
//         curr->prev=curr->next;
//         curr->next=back;
//         curr=curr->prev;
//     }
//     return back->prev;
// }

// Method 3: using recursive approach(efficient approach)
Node* reverseLL(Node* head){
    //Base case
    if(head==NULL || head->next==NULL)
    return head;

    Node* new_head=reverseLL(head->next);

    Node* front=head->next;
    front->next=head;
    head->next=NULL;

    return new_head;
}

int main()
{
    Node* head= NULL;
    head= InsertAtFirst(40,head);
    head= InsertAtFirst(30,head);
    head= InsertAtFirst(20,head);
    head= InsertAtFirst(10,head);
    head= InsertAtFirst(0,head);
    cout<<"Linked list before reversing: "<<endl;
    printLL(head);
    cout<<"Linked list after reversing: "<<endl;
    head=reverseLL(head);
    printLL(head);
    free(head);

    return 0;
}
