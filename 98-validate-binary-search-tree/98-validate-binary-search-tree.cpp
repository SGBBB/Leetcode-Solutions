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
    bool helper(TreeNode* root,long minRange , long maxRange ){
        if(!root) return true;
        
        bool L=helper(root->left,minRange ,root->val);
        bool R=helper(root->right,root->val,maxRange);
        /*
        If root is not null then im just checking whether root->val lie under min and max Range. 
        */
        return L and R and minRange<(root->val)  and (root->val)< maxRange  ; 
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper( root, LONG_MIN , LONG_MAX ); 
        
    }
    /*Time Complexity is O(N) */
};