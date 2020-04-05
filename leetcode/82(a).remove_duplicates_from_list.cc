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
	while(head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl; 
}

bool check(ListNode*head) {
    if(head == NULL or head->next == NULL) return true;
    return false;
}

ListNode* deleteDuplicates(ListNode* head) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    if(check(head)) return head;         
    ListNode*pre = NULL,*prev = head,*cur = prev->next;
    while(cur) {
        if(prev->val == cur->val) {
            // Deleting every node whoes value is same as prev Node.
            while(prev->val == cur->val) {
            	// if we have no node left.
            	// we can return.
                if(cur->next == NULL){
                    cur = NULL;
                    break;
                }
                cur = cur->next;
            }
            prev->next = cur;
            if(cur == NULL and pre == NULL) return NULL;
            if(pre == NULL) head = cur;
            else pre->next = cur;
            if(check(cur)) return head;
            } else pre = prev; 
        prev = cur;
        cur = cur->next;
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
		ListNode*head = insert();
		// printList(head);
		head = deleteDuplicates(head);
		printList(head);
	}
	return 0;
}


// Sample Input :

// 5
// 1 2 2 2 2 2 2 2 2 3 -1
// 1 1 1 3 3 3 -1
// 1 8 9 9 9 4 3 -1
// 1 1 1 1 1 1 2 -1
// 7 8 9 9 6 -1

Sample Output :



// 2 
// 7 8 6 
// 1 3 
// 1 8 4 3 