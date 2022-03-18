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
    //Ye solution ne moj krdeee
    TreeNode *prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(root){
            flatten(root->right);
            flatten(root->left);
            
            //I'm done visiting my lef tand right subtree
            root->right=prev,
            root->left=NULL,
            prev=root;
            
        }
    }
};