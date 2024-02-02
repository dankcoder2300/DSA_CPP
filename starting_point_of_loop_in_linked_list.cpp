// Program to find the starting point of a loop in linked list
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

void createCycle(Node* &head,int pos) {
    Node* ptr = head;
    Node* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}

// Node *detectCycle(Node *head) {
//     unordered_map<Node*,int> mp;
//     Node* temp=head;
//         while(temp!=NULL)
//          {
//             if(mp.find(temp)!=mp.end())
//             return temp;

//             mp[temp]=1;
//             temp=temp->next;
//          }
//          return NULL;
//     }

// Method 2: Using tortoise and hare appraoch (optimal approach)
Node* detectCycle(Node *head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
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

    //creating cycle
    createCycle(head,2);
    
    Node* received_node=detectCycle(head);
    if(received_node==NULL){
        cout<<"No cycle detected in linked list"<<endl;
    }
    else{
        Node* temp=head;
        int pos=0;
        while(temp!=received_node)
        {
            pos++;
            temp=temp->next;
        }
        cout<<"Tail connects at position "<<pos<<endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}