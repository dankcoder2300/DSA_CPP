/* Program to: You are given a linked list containing 'n' nodes, where every node in the linked list contains two pointers:
(1) ‘next’ which points to the next node in the list
(2) ‘random’ which points to a random node in the list or 'null'.
Your task is to create a 'deep copy' of the given linked list and return its head.*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;
        Node(int value) {
            val = value;
            next = NULL;
            random = NULL;
        }
};

// Method 1: Using map to create deep copy of nodes(Brute force approach)
// Node* copyRandomList(Node* head) {
//         Node* temp=head;
//         unordered_map<Node*,Node*> mpp;
//         //creating copies of every nodes and storing it into map
//         while(temp!=NULL)
//         {
//             Node* newNode=new Node(temp->val);
//             mpp[temp]=newNode;
//             temp=temp->next;
//         }
//         //assigning next and random pointers to copied nodes
//         temp=head;
//         while(temp!=NULL)
//         {
//             Node* copyNode=mpp[temp];
//             copyNode->next=mpp[temp->next];
//             copyNode->random=mpp[temp->random];
//             temp=temp->next;
//         }
//         return mpp[head];
//     }

// Method 2: Inserting copy Nodes in between nodes and assigning pointers(Optimal approach)
Node* copyRandomList(Node* head) {
        Node* temp=head;
        // creating new nodes and insering between two nodes
        while(temp!=NULL)
        {
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        //assigning random pointers to new nodes
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node* dummyNode=new Node(-1);
        temp=dummyNode;
        Node* itr=head;
        //rearranging old next pointer and new nodes next pointer
        while(itr!=NULL)
        {
            Node* fast=itr->next->next;
            temp->next=itr->next;
            itr->next=fast;
            temp=temp->next;
            itr=fast;
        }
        return dummyNode->next;
    }

void printList(Node* head) {
    while(head != NULL) {
        cout<<head->val<<':';
        head->next != NULL ? cout<<head->next->val:cout<<"NULL";
        head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
        cout<<endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;
    
    cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    printList(head);
    
    cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    Node* newHead = copyRandomList(head);
    printList(newHead);
    return 0;
}