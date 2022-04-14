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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /*if both hold null address then simply return null*/    
        if(!root1 and !root2) return NULL;
        if(root1 and !root2) return root1;
        if(!root1 and root2) return root2;
        // at this moment both trees have their heads
        auto L=mergeTrees(root1->left,root2->left);
        auto R=mergeTrees(root1->right,root2->right);
        TreeNode* node=new TreeNode();
        node->val=root1->val+root2->val;
        node->left=L;
        node->right=R;
        return node;
        
    }
};