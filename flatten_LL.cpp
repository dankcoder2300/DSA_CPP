/* Program to a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:
(1) ‘next’ which points to the next node in the list
(2) ‘child’ pointer to a linked list where the current node is the head.
Each of these child linked lists is in sorted order and connected by 'child' pointer.
Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.*/
#include<bits/stdc++.h>
using namespace std;

//Definition for linked list.
class Node {
public:
int data;
Node *next;
Node *child;

Node() : data(0), next(nullptr), child(nullptr){};
Node(int x) : data(x), next(nullptr), child(nullptr) {}
Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Method 1:Brute Force Approach
// Node* convertArrToFlatLL(vector<int> arr)
// {
// 	Node* newHead=new Node(arr[0]);
// 	Node* temp=newHead;
// 	for(int i=1;i<arr.size();i++)
// 	{
// 		Node* newNode=new Node(arr[i]);
// 		temp->child=newNode;
// 		temp->next=NULL;
// 		temp=temp->child;
// 	}

// 	return newHead;
// }

// Node* flattenLinkedList(Node* head) 
// {
// 	// Write your code here
// 	Node* temp=head;
// 	vector<int> arr;
// 	while(temp!=NULL)
// 	{
// 		Node* temp2=temp;
// 		while(temp2!=NULL)
// 		{
// 			arr.push_back(temp2->data);
// 			temp2=temp2->child;
// 		}
// 		temp=temp->next;
// 	}
// 	sort(arr.begin(),arr.end());
// 	head=convertArrToFlatLL(arr);
	
//     return head;
// }

// Method 2: Using Merge Sort Approach
Node* mergeTwoHead(Node* temp1,Node* temp2)
{
	if(temp1->data<=temp2->data)
	temp2->next=NULL;
	else
	temp1->next=NULL;
	
	Node* dummyNode=new Node(-1);
	Node* temp=dummyNode;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data<=temp2->data)
		{
			temp->child=temp1;
			temp=temp->child;
			temp1=temp1->child;
		}
		else
		{
			temp->child=temp2;
			temp=temp->child;
			temp2=temp2->child;
		}
		temp->next=NULL;
	}
		if(temp1)
		temp->child=temp1;
		if(temp2)
		temp->child=temp2;
		
		if(dummyNode->child)
		dummyNode->child->next=NULL;
	return dummyNode->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)
	return head;

	Node* mergeHead=flattenLinkedList(head->next);

	head=mergeTwoHead(head,mergeHead);

	return head;

}
