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
    vector<int> helper(TreeNode* root){
        vector<int> ans;
        if(root){
            vector<int> res1=helper(root->left),
                        res2=helper(root->right);
            int x=res1[1]+res2[1]+root->val,
                y=res1[0]+res2[0] ;
            return {max(x,y) , y};
            
        }
        return {0,0};
    }
public:
    int rob(TreeNode* root) {
        auto res=helper(root);
        return res[0];
    }
};