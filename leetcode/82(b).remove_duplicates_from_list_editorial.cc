static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr)
            return head;
        
        for (ListNode* node = head,*prev=head;node!=nullptr;prev=node,node=node->next){
            while (node!=nullptr && node->next!=nullptr && node->val==node->next->val){
                int value = node->val;
                while (node!=nullptr && node->val==value)
                    node=node->next;
                
                if (prev->val==value){
                    prev = node;
                    head = node;
                }
                else prev->next = node;
            }
            if (node==nullptr)
                break;
        }
        
        return head;
    }
};
// Time: O(n)
// Space: O(1)