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
        if(!root) NULL;
        int curr=root->val;
        if( curr>p->val and curr>q->val ) /* route to left side  */
        return lowestCommonAncestor(root->left,p,q);
        if(curr<p->val and curr<q->val )
        return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};