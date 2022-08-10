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
    TreeNode* convertHeightBalancedBinaryTree(vector<int>& nums,int i,int j){
        if(i==j){
            
            TreeNode * node=new TreeNode(nums[i]);
            return node;
        }
        if(i<j){
            int pos=(i+j)/2;
            TreeNode * node=new TreeNode(nums[pos]);
            node->left=convertHeightBalancedBinaryTree(nums,i,pos-1);
            node->right=convertHeightBalancedBinaryTree(nums,pos+1,j);
            return node;
        }
         
        return NULL;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 0 9 19
        return convertHeightBalancedBinaryTree(nums,0,nums.size()-1);
         
        
    }
};