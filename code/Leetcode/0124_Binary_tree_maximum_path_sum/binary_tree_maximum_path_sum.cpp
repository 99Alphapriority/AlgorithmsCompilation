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
    int dfs(TreeNode* root, int currSum, int& maxSum)
    {
            if(root == NULL)
                return 0;

            int leftSum = max(dfs(root->left, currSum, maxSum),0);
            int rightSum = max(dfs(root->right, currSum, maxSum),0);

            currSum = root->val + leftSum + rightSum;
            maxSum = max(currSum, maxSum);
            return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {

        int currSum = 0;
        int maxSum = INT_MIN;

        dfs(root, currSum, maxSum);

        return maxSum;
        
    }
};
