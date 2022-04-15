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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root->val<low){
            //If root->val<low then i'll not return this root also ill not explore its left as well becoz guys to its left subtree will surely holding smALLER VALUES,INSTEAD ILL RETURN ITS RIGHT SUBTREE
            root->left=NULL;
            return trimBST(root->right,low,high);
        }
        else if(root->val>high){
            root->right=NULL;
            return trimBST(root->left,low,high);
        }
        //Now root->val is inside range of [low ,high]
            auto L=trimBST(root->left,low,high);
            auto R=trimBST(root->right,low,high);
            root->left=L,
            root->right=R;
        
        return root;
    }
};