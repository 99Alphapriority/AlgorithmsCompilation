/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findHeight(TreeNode* root){ //dfs
        if(root == nullptr) return 0;

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        if(left == -1 || right == -1) return -1;
        else if(abs(left - right) > 1) return -1;

        return (1+max(left, right));
    }
    bool isBalanced(TreeNode* root) {
        int x = findHeight(root);
        if(x == -1) return false;
        return true;
    }
};
