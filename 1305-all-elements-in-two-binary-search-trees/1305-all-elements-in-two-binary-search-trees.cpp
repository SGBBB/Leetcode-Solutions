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
    vector<int> inorder(TreeNode* root){
        vector<int> ans;
        if(root){
            auto arr1=inorder(root->left);
            
            ans.insert(ans.end(),arr1.begin(),arr1.end());
            ans.push_back(root->val);
            auto arr2=inorder(root->right);
            ans.insert(ans.end() ,arr2.begin(),arr2.end());
        }
        
        return ans;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        auto List1=inorder(root1),List2=inorder(root2);
        int i=0,j=0,len1=List1.size(),len2=List2.size();
        vector<int> ans;
        for(;i<len1 and j<len2;){
            int element1=List1[i],element2=List2[j];
            if(element1<element2) ans.push_back(List1[i++]);
            else ans.push_back(List2[j++] );
        }
        
        for(;i<len1;) ans.push_back(List1[i++]);
        for(;j<len2;)ans.push_back(List2[j++]);
        return ans;
    }
};