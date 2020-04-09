#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class ListNode {
public:
	int val;
	ListNode*next;
	ListNode(const int data){
		this->val = data;
		this->next = NULL;
	}
};

ListNode* insert() {
	int data;
	cin >> data;
	if(data == -1) return NULL;
	ListNode*root = new ListNode(data);
	root->next = insert();
	return root;
}

void printList(ListNode*head) {
	while(head->next) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << head->val << endl; 
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	ListNode*newList = NULL;
	ListNode*temp = NULL;
	ListNode*prev = NULL;
    while(l1 and l2) {
    	if(l1->val <= l2->val) {
    		temp = l1;
    		l1 = l1->next;
    	} else {
    		temp = l2;
    		l2 = l2->next;
    	}
    	temp->next = NULL;
    	if(prev) prev->next = temp;
    	else newList = temp;
    	prev = temp;
    }  
    if(l1 == NULL) prev->next = l2;
	else if(l2 == NULL) prev->next = l1;
	return newList;
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
		ListNode*List1 = insert();
		ListNode*List2 = insert();
		ListNode*List = mergeTwoLists(List1,List2);
		cout << "Final List : ";
		printList(List);
	}
	return 0;
}


// Sample Input :

// 3
// 1 3 7 9 15 -1
// 2 4 5 6 8 10 -1
// 1 2 3 5 6 -1
// 4 7 8 9 10 -1
// 1 3 -1
// 2 -1

// Sample Output :

// Final List : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 15
// Final List : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
// Final List : 1 -> 2 -> 3