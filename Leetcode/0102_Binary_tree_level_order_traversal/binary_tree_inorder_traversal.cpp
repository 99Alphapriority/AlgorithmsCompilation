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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        q.push(root);

        while(!q.empty())
        {
            int count = q.size();
            vector<int> res;

            for(int i = 0; i< count ; i++)
            {
                TreeNode* node = q.front();

                res.push_back(node->val);

                q.pop();

                if(node->left != NULL)
                    q.push(node->left);
            
                if(node->right != NULL)
                    q.push(node->right);

            }

            ans.push_back(res);
        }

        return ans;
    }
};
