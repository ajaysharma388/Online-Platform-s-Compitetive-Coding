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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* ans_1 = l1;
        ListNode* ans_2 = l2;
        
        int add_one = 0;
        
        for (; l1 && l2; l1 = l1->next, l2 = l2->next)
        {
            int value = l1->val + l2->val;
            if (add_one)
            {
                value ++;
                add_one = 0;
            }

            if (value >= 10)
            {
                add_one = 1;
                value -= 10;
            }
            cout<<value<<endl;
            l1->val = l2->val = value;
            head1 = l1;
            head2 = l2;
        }
        for (; l1; l1 = l1->next)
        {
            //cout<<"not here"<<endl;
            if (add_one)
            {
                l1->val += 1;
                add_one = 0;
            }
            if (l1->val >= 10)
            {
                l1->val -= 10;
                add_one = 1;
            }
            head1 = l1;
            head2 = nullptr;
        }
        for (; l2; l2 = l2->next)
        {
            //cout<<"not here"<<endl;
            if (add_one)
            {
                l2->val += 1;
                add_one = 0;
            }
            if (l2->val >= 10)
            {
                l2->val -= 10;
                add_one = 1;
            }
            head2 = l2;
            head1 = nullptr;
        }
        if (add_one)
        {
            cout<<"not add one"<<endl;
            if (head1)
            {
                ans_2->val = 1;
                ans_2->next = nullptr;
                head1->next = ans_2;
                //cout<<"head1 value"<<head1->val<<endl;
            }
            else
            {
                ans_1->val = 1;
                ans_1->next = nullptr;
                head2->next = ans_1;
            }
        }
        
         
        return (head1)? ans_1: ans_2;
    }
};