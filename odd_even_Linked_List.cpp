//Program to arrange odd index at starting of linked list and then even index after odd index of linked list
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Method 1: Using extra array approach (brute force approach)
// Node* OddEvenLL(Node* head)
// {
//    vector<int> arr;
//    Node* temp=head;

//    //for odd index nodes
//    while(temp!=NULL && temp->next!=NULL){
//     arr.push_back(temp->data);
//     temp=temp->next->next;
//    }
//    //if last odd index is remaining to push into array
//    if(temp){
//     arr.push_back(temp->data);
//    }

//    //for even index nodes
//    temp=head->next;
//    while(temp!=NULL && temp->next!=NULL){
//     arr.push_back(temp->data);
//     temp=temp->next->next;
//    }
//    //if last even index node is remaining
//    if(temp){
//     arr.push_back(temp->data);
//    }

//    //inserting array values into linked list
//    temp=head;
//    for(int i=0;i<arr.size();i++)
//    {
//         temp->data=arr[i];
//         temp=temp->next;
//    }

//     return head;
// }

// Method 2: Using two pointers approach
Node* OddEvenLL(Node* head)
{
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;

    return head;
}

int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    cout << "Original Linked List: ";
    printLinkedList(head);

    cout<<"Linked List after modification is: ";
    head=OddEvenLL(head);
    printLinkedList(head);

    delete(head);
    delete(second);
    delete(third);
    delete(fourth);
    delete(fifth);
    return 0;
}

