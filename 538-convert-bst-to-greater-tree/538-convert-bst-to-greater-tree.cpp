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
    int prefix_sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        convertBST(root->right);
        int temp=root->val;
        
        root->val+=prefix_sum,
        
        prefix_sum+=temp;
        cout<< root->val<<" === " <<prefix_sum <<" " <<temp<<endl;
        convertBST(root->left);
        return root;
    }
};
/*
How will I go abput solving this problem??
Initially i must move to the right subtree then to he left subtree

Dont have to worry about anything just add norder successor value to  root->val ;
*/