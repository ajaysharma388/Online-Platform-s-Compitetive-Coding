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
    bool isPalindrome(ListNode* head) {
        ios::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> a;
        ListNode *t=head;
        while(t!=NULL)
        {
            a.push_back(t->val);
            t=t->next;
        }
        if(a.size()%2==0)
        {
            for(int i=0;i<a.size()/2;i++)
            {
                if(a[i]!=a[a.size()-1-i])
                    return false;
            }
        }
         if(a.size()%2!=0)
        {
            for(int i=0;i<=a.size()/2;i++)
            {
                if(a[i]!=a[a.size()-1-i])
                    return false;
            }
        }
        return true;
        
    }
};