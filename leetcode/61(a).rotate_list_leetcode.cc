class Solution {
public:
    int length(ListNode*head) {
        int l = 0;
        while(head) {
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int len = length(head);
        if(len == 0 or len == 1 or k == 0) return head;
        if(len <= k) k%=len;
        ListNode*pre = head;
        ListNode*cur = head;
        for(int i = 0; i < k; ++i) 
            cur = cur->next;
        while(cur->next!=NULL) {
            pre = pre->next;
            cur = cur->next;
        }
        cur->next = head;
        head = pre->next;
        pre->next = NULL;        
        return head;
    }
};