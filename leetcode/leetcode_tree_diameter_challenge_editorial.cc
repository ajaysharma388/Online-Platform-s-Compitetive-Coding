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
    int max_diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        get_depth(root);
        return max_diameter;
        
    }
    int get_depth(TreeNode* root) {
        if (root == NULL) return 0;
        int left_depth = get_depth(root->left);
        int right_depth = get_depth(root->right);
        max_diameter = max(max_diameter,left_depth+right_depth);
        return max(left_depth, right_depth)+1;

    }
};