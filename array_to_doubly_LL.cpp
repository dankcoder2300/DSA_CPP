//Program to convert a given array to doubly linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data1,Node*prev1,Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
};

//Function to convert array into doubly linked list
Node* convertArrtoLL(vector<int> arr){
    Node* head= new Node(arr[0]);
    Node* ptr=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],ptr,nullptr);
        ptr->next=temp;
        ptr=ptr->next;
    }
    return head;
}

//Function to print the doubly linked list
void printLL(Node* head){
    Node* ptr=head;
    int cnt=0;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
        cnt++;
    }
    cout<<"null"<<endl;
    cout<<"The length of Linked List is: "<<cnt<<endl;
}

//Function to search element in a linked list
bool searchElement(Node* head,int val){
    Node* ptr=head;
    while(ptr!=NULL){
        if(ptr->data==val)
        return true;

        ptr=ptr->next;
    }
    return false;
}

int main()
{
    vector<int> arr= {1,2,3,4};
    Node *head= convertArrtoLL(arr);
    printLL(head);
    int val=3;
    bool ans=searchElement(head,3);
    if(ans==1)
    cout<<"Element "<<val<<" found"<<endl;
    else
    cout<<"Element "<<val<<" not found"<<endl;

    return 0;
}