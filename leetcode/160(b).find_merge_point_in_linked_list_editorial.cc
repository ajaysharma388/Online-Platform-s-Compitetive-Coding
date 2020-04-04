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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode *pA = headA, *pB = headB, *intersection = NULL;
        cout << "pa_val: " << pA << ", pb_val: " << pB << endl;
        int lA = 0 , lB = 0;
        ListNode* lastA; 
        ListNode* lastB;
        while (pA) {
            lA++;
            lastA = pA;
            pA = pA->next;        
        }
        
        while (pB) {
            lB++;
            lastB = pB;
            pB = pB->next;        
        }
        if (lastA != lastB)
            return NULL;
        
        pA = headA;
        pB = headB;

        for (int i = 0; i < lA- lB; i++)
            pA = pA->next;

        for (int i = 0; i < lB- lA; i++)
            pB = pB->next;
        
        while(pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};