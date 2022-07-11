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
    map<int ,int > store;
    void dfs(TreeNode* node,int position=0){
        if(node!=NULL){
            store[position]=node->val;
            dfs(node->left,position+1);
            dfs(node->right,position+1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        for(auto it:store)
            ans.push_back(it.second);
        return ans;
    }
};