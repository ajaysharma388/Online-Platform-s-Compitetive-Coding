class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * slow = head;
        ListNode * fast = head;
        if(!head)return head;
        ListNode * tt = head;
        int c = 0;
        while(tt)
        {
            tt = tt->next; c++;
        }
        k = k% c;
        for(int i =0;i<k;i++)fast = fast->next;
        while(fast->next)
        {
            fast = fast->next; slow = slow->next;
        }
        fast->next = head;
        ListNode * newhead = slow->next;
        slow->next = NULL;
        return newhead;
    }
};