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
    vector<vector<int>> res;
    void dfs(TreeNode* node,int height=0){
        if(node!=NULL){
            if(height==res.size())
                res.push_back({});
            res[height].push_back(node->val);
            dfs(node->left,height+1);
            dfs(node->right,height+1);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        dfs(root);
        return res;
    }
};