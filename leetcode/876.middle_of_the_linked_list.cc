#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
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


class ListNode {
public:
    int val;
    ListNode*next;
    ListNode(const int data) {
        this->val = data;
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
    while(head->next) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val;
    return;
}

ListNode* middleNode(ListNode* head) {
    if(head == NULL) return head;
    int count = 0;
    ListNode*ptr = head;
    while(ptr) {
        count++;
        ptr = ptr->next;
    }
    ptr = head;
    for(int i = 1; i <= count/2; ++i) {
        ptr = ptr->next;
    }
    return ptr;
}

int main() {
    fastio(true);
    ListNode*head = createList();
    printList(head);
    return 0;
}