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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){ 
            return root;
        }
        TreeNode* L=lowestCommonAncestor(root->left, p,q);
        TreeNode* R=lowestCommonAncestor(root->right, p,q);
        /*
        If i get response from either side then return it becoz another node might be residing in below subtree.
        */
        if(!L)
            return R;
        if(!R)
            return L;
    // This means that Im receiving response from both the subtreess left and right
        return root;
        // return (!L)?R:(!R)?L:root;
        // return root;
    }
};