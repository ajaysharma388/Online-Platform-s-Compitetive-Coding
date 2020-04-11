#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

class node {
public:
	int data;
	node*next;
	node(const int data) {
		this->data = data;
		this->next = NULL;
	}
};

node* createList() {
	int data;
	cin >> data;
	if(data == -1) return NULL;
	node*cur = new node(data);
	cur->next = createList();
	return cur;
}

void printList(node*head) {
	if(head == NULL) return;
	while(head->next != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << head->data << endl;
	return;
}

// Iterative Solution with time complexity of the order O(N).
// and the space complexity of this function is O(1);

node* reverseList1(node*head) {
	if(head == NULL or head->next == NULL) return head;
	node*cur = head;
	node*pre = head->next;
	node*newhead = NULL;
	while(pre) {
		cur->next = newhead;
		newhead = cur;
		cur = pre;
		pre = pre->next;
	}
	cur->next = newhead;
	return cur;
}

// Recursive Approach to reverse the linked List.
// Time Complexity is of the order O(N).
// Space Complexity is O(N) as takes N stack calls.

node* reverseList2(node*head) {
	if(head->next == NULL) return head;
	node*temp = reverseList2(head->next);
	node*ptr = temp;
	while(temp->next) {
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return ptr;
}

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		node*head = createList();
		head = reverseList2(head);
		printList(head);
	}
	return 0;
}