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

    int ans = 0;
    int currMax = 0;
    
    void dfs(TreeNode* root, int currMax)
    {
        if(root == NULL)
            return;
        
        if(root->val >= currMax)
        {
            ans++;
            //printf("root->val %d currMax %d\n",root->val, currMax);
        }

        dfs(root->left, max(currMax, root->val));
        dfs(root->right, max(currMax, root->val));

    }

    int goodNodes(TreeNode* root) {

        currMax = root->val;

        dfs(root, currMax);

        return ans;
    }
};
