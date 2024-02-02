// Program to detect a loop in linked list
#include<bits/stdc++.h>
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

// Method 1: using onordered map (brute force approach)
// bool detectLoop(Node* head)
// {
//     unordered_map<Node*,int> mp;

//     Node* temp=head;

//     while(temp!=NULL)
//     {
//         if(mp.find(temp)!=mp.end()){
//             return true;
//         }

//         mp[temp]=1;
//         temp=temp->next;
//     }

//     return false;
// }

// Method 2: Using tortoise and hare appraoch (optimal approach)
bool detectLoop(Node *head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main() 
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}