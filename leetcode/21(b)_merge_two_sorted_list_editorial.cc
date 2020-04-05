/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
iterative...
*/
class Solution {
public:
    void merge(ListNode** l1, ListNode** head) {
        (*head)->next = *l1;
        
        (*l1) = (*l1)->next;
        (*head) = (*head)->next;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        ListNode *resHead, *movHead, *l1Prev, *l2Prev;
        
        if(l1->val <= l2->val) {
            movHead = resHead = l1;
            l1 = l1->next;
        }
        else {
            movHead = resHead = l2;
            l2 = l2->next;
        }
        
        while(l1 and l2) {
            l1Prev = l1;
            l2Prev = l2;
            
            if(l1->val <= l2->val) {
                merge(&l1, &movHead);
            }
            else {
                merge(&l2, &movHead);
            }
        }
        
        if(!l1){
            // cout<<"1. "<<movHead->val<<" "<<l1Prev->val<<" "<<l2->val<<endl;
            movHead->next = l2;
        }
        if(!l2) {
            // cout<<"2. "<<movHead->val<<" "<<l2Prev->val<<" "<<l1->val<<endl;
            movHead->next = l1;
        }
        
        return resHead;
    }
};