#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class ListNode {
public:
	int val;
	ListNode*next;
	ListNode(const int value) {
		this->val = value;
		this->next = NULL;
	}
};

ListNode* createList() {
	int data;
	cin >> data;
	if(data == -1) return NULL;
	ListNode*cur = new ListNode(data);
	cur->next = createList();
	return cur;
}

void printList(ListNode*head) {
	if(head == NULL) return;
	while(head->next) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << head->val << endl;
	return;
}

ListNode* swapPairs(ListNode* head) {
	int swap = 0;
	ListNode*pre = head;
	while(pre) {
		swap++;
		pre = pre->next;
	}
	if(swap < 2) return head;
	swap/=2;
	pre = head;
	ListNode*tHead = NULL;
	ListNode*cur = pre->next;
	for(int i = 1; i <= swap; ++i) {
		if(pre == head) head = cur;
		else tHead->next = cur;
		pre->next = cur->next;
		cur->next = pre;
		if(pre->next == NULL) return head;
		tHead = pre;
		pre = pre->next;
		cur = pre->next; 
	}
	return head;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		ListNode*head = createList();
		head = swapPairs(head);
		printList(head);
	}
	return 0;
}

// Sample Input :

// 5
// 12 34 56 78 90 -1
// 3 6 9 12 15 -1
// 10 20 30 40 -1
// 11 22 -1
// 1 2 3 4 5 6 7 8 9 10 -1

// Sample Output :

// 34 -> 12 -> 78 -> 56 -> 90
// 6 -> 3 -> 12 -> 9 -> 15
// 20 -> 10 -> 40 -> 30
// 22 -> 11
// 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> 8 -> 7 -> 10 -> 9