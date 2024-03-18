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
    void dfs(TreeNode* root, vector<string>& ans, string str)
    {
        if(root->left == NULL && root->right == NULL)
        {
            str += to_string(root->val);
            ans.push_back(str);
            str.pop_back();
            return;
        }

        str += to_string(root->val);
        str += "->";

        if(root->left != NULL)
            dfs(root->left, ans, str);
        if(root->right != NULL)
            dfs(root->right, ans, str);

        str.pop_back();
        str.pop_back();

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = "";

        dfs(root, ans, str);

        return ans;
    }
};
