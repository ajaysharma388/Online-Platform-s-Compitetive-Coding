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


int length(node*head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;        
}

bool isPalindrome(node* head) {
    int len = length(head);
    node*temp = head;
    for(int i = 1; i < len/2; ++i) {
        temp = temp->next;            
    }
    node*l1 = head;
    node*l2 = temp->next;
    temp->next = NULL;
    l2 = reverseList1(l2);
    while(l1 and l2) {
    	if(l1->data != l2->data) return false;
    	l1 = l1->next;
    	l2 = l2->next;
    }
    return true;
}

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		node*head = createList();
		bool ans = isPalindrome(head);
		(ans) ? cout << "true" : cout << "false" ;
		cout << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 1 2 2 1 -1
// 10 20 30 40 -1
// 11 22 33 44 55 -1

// Sample Output :

// true
// false
// false