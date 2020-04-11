/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int processTheTree(TreeNode*root,int &maxPossible) {
        if(root == NULL) return 0;
        int leftLargest = processTheTree(root->left,maxPossible);
        int rightLargest = processTheTree(root->right,maxPossible);        
        maxPossible = max(maxPossible,leftLargest+rightLargest);
        return max(leftLargest,rightLargest)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxPossible = 0;
        processTheTree(root,maxPossible);
        return maxPossible; 
    }
};