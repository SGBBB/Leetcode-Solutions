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
long totalSum=0,res=0;
class Solution {
    long calSumTree(TreeNode* root){
        int subTreeSum=0;
        if(root){
            subTreeSum=root->val+calSumTree(root->left)+calSumTree(root->right);
            res=max(res,(totalSum-subTreeSum)*   subTreeSum);
            
        }
        return subTreeSum;
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum=0,res=0;
        totalSum=calSumTree(root);
        calSumTree(root);
        return  res%int(1e9+7);
        
    }
};
/*
How will I make progress in this problme?
Try to think about smaller sub-problems eventually i'll make progress to larger susb-problems.
If Im at leaf node then i would definitely have returned it.
Try to hit the problem in every possible means
Seems like i have to calculate the sum of whole tree

*/