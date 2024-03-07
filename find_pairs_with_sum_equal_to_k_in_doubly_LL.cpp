// Program to find Find pairs with given sum in doubly linked list
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
        prev=nullptr;
        next=nullptr;
    }

    public:
    Node(int data1,Node* prev1,Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};

//Function to insert node at the beginning of a doubly linked list
Node* InsertatFirst(int data,Node* head)
{
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    
    temp->next=head;
    temp->prev=nullptr;
    head->prev=temp;
    head=temp;

    return head;
}

//Function to print doubly Linked List
void printLL(Node* head)
{
    Node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"null"<<endl;
}

// Method 1: Brute Force Approach
// vector<pair<int, int>> findPairs(Node* head, int k)
// {
//     Node* temp1=head;
//     vector<pair<int,int>> ans;
//     while(temp1!=NULL)
//     {
//         Node* temp2=temp1->next;
//         while(temp2!=NULL && (temp1->data+temp2->data)<=k)
//         {
//             if((temp1->data+temp2->data)==k)
//             {
//                 ans.push_back({temp1->data,temp2->data});
//             }
//             temp2=temp2->next;
//         }
//         temp1=temp1->next;
//     }
//     return ans;
// }

// Method 2: Using two pointer approach
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    Node* low=head;
    Node* high=head;
    while(high->next!=NULL)
    high=high->next;

    while(low->data<high->data)
    {
        if((low->data+high->data)==k)
        {
            ans.push_back({low->data,high->data});
            low=low->next;
            high=high->prev;
        }
        else if((low->data+high->data)>k)
        high=high->prev;
        else
        low=low->next;
    }
    return ans;
}
int main() {
  Node* head = NULL;
  head = InsertatFirst(9, head);
  head = InsertatFirst(4, head);
  head = InsertatFirst(3, head);
  head = InsertatFirst(2, head);
  head = InsertatFirst(1, head);
  int k;
  cout<<"Enter the Number: ";
  cin>>k;
  vector<pair<int,int>> ans=findPairs(head,k);
  cout << "Pairs with sum equal to k: " << endl;
  for(auto it:ans)
  {
    cout<<it.first<<","<<it.second<<endl;
  }
  return 0;
}