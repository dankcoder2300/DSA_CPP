//Program to delete the nth node from the end of a linked list
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

// Method 1: Brute force approach
// Node* deleteNthNodeEnd(Node* head,int n)
// {
//     if(head==NULL)
//     return head;

//     Node* temp=head;
//     int cnt=0;

//     while(temp!=NULL)
//     {
//         cnt++;
//         temp=temp->next;
//     }

//     //if we want to delete the first node
//     if(n==cnt)
//     {
//         Node* newHead=head->next;
//         free(head);
//         return newHead;
//     }

//     //delete the cnt-n+1 th node
//     int pos=cnt-n;
//     int i=1;
//     temp=head;
//     while(i<pos)
//     {
//         temp=temp->next;
//         i++;
//     }
//     Node* delNode=temp->next;
//     temp->next=temp->next->next;
//     free(delNode);

//     return head;
// }

// Method 2: Using two pointers approach
Node* deleteNthNodeEnd(Node* head, int n)
{
    Node* fast=head;
    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }
    // if we want to delete the head node
    if(fast==NULL)
    {
        Node* newHead=head->next;
        free(head);
        return newHead;
    }

    Node* slow=head;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }

    Node* delNode=slow->next;
    slow->next=slow->next->next;
    free(delNode);

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
    head=deleteNthNodeEnd(head,3);
    printLinkedList(head);

    delete(head);
    delete(second);
    delete(third);
    delete(fourth);
    delete(fifth);
    return 0;
}

