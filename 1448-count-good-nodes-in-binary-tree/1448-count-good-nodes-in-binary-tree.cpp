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
    int countGoodNodes(TreeNode* root,int parentNodeVal=INT_MIN){
        int count=0;
        if(root){
            cout<<parentNodeVal<<endl;
             if(root->val>=parentNodeVal)
                count++;
            count+=countGoodNodes(root->left,max(parentNodeVal,root->val));
            count+=countGoodNodes(root->right,max(parentNodeVal,root->val));
        }
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root);
    }
};