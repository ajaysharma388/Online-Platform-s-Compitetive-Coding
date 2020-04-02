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
        ListNode*head = NULL;
        ListNode*temp = NULL;
        int carry = 0;
        while(l1 != NULL and l2 != NULL) {
            int data = (l1->val + l2->val) + carry;
            carry = data/10;
            data = data%10;
            if(head == NULL){
                head = new ListNode(data);
                temp = head;
            } else { 
                temp->next = new ListNode(data);
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = (l1 == NULL) ? l2 : l1;
        while(l1 != NULL) {
            int data = l1->val + carry;
            carry = data/10;
            data = data%10;
            temp->next = new ListNode(data);
            temp = temp->next;
            l1 = l1->next;
        }
        while(carry) {
            temp->next = new ListNode(carry%10);
            carry /= 10;
            temp = temp->next;
        }
        return head;
    }
};