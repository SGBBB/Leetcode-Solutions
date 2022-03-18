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
     void pathSumFinder(TreeNode *root , vector<vector<int>> &ans, 
                   int target,vector<int> temp ){
        if( root  ){
            cout<<target<<endl;
            
            
            temp.push_back(root->val);
            if(!root->left and !root->right and !(target-root->val) ) {
                cout<<"kabhi aya ky "<<endl;
                ans.push_back(temp); return;
            }
            pathSumFinder(root->left,ans,target-root->val,temp);
            pathSumFinder(root->right,ans,target-root->val,temp);
            
            
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        pathSumFinder(root,ans,targetSum,temp);
        return ans;
    }
};