/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // This Solution is of the oreder.
    // Time Complexity = O(m + n)
    // Space Complexity = O(1)
    int length(ListNode*head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        // Takes O(m) time to calculate the length for first List.
        int m = length(head1);
        // Takes O(n) time to calculate the length for second List.
        int n = length(head2);
        // considering the first list as the longer.
        int d = abs(m - n); 
        // if first list is not longer then we will swap.
        if(m < n) {
            swap(head1,head2);
        }
        for(int i = 0; i < d; ++i) {
            head1 = head1->next;
        }
        for(int i = 0; i < n; ++i) {
            if(head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return NULL;
    }
};