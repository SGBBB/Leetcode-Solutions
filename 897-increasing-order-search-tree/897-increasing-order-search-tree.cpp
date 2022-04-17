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
    TreeNode * nextNode=NULL;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root){ 
        increasingBST(root->right);
        //Write some logic
        root->right=nextNode,
        nextNode=root;
        increasingBST(root->left);
        root->left=NULL;
        }
        return nextNode;
    }
};