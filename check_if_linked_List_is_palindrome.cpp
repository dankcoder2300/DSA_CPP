//Program to check whether a linked list is palindrome or not
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

// Method 1: Using Stack based approach (brute force approach)
// bool isPalindrome(Node* head)
// {
//     Node* temp=head;
//     stack<int> st;

//     while(temp!=NULL)
//     {
//         st.push(temp->data);
//         temp=temp->next;
//     }

//     temp=head;

//     while(temp!=NULL)
//     {
//         if(st.top()!=temp->data)
//         return false;

//         st.pop();
//         temp=temp->next;
//     }
//     return true;
// }

// Method 2: Using Tortoise and Hare approach
 Node* reverseLL(Node* head)
    {
        if(head==NULL || head->next==NULL)
        return head;

        Node* newhead=reverseLL(head->next);
        Node*front=head->next;
        front->next=head;
        head->next=NULL;

        return newhead;
    }

    bool isPalindrome(Node* head) 
    {
        if(head==NULL || head->next==NULL)
        return true;
        
        Node* slow=head;
        Node* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        Node* newhead=reverseLL(slow->next);
        Node* first=head;
        Node* second=newhead;
        while(second!=NULL)
        {
            if(first->data!=second->data)
            {
                reverseLL(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newhead);
        return true;
    }
    
int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    cout << "Original Linked List: ";
    printLinkedList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    delete(head);
    delete(second);
    delete(third);
    delete(fourth);
    delete(fifth);
    return 0;
}

