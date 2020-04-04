class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode*prev = head;
        ListNode*cur = cur = prev->next;
        while(cur != NULL) {
            if(cur->val == prev->val) {
                ListNode*temp = cur;
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};