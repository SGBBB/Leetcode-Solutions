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
    unordered_map<int,int> M;//{pre ordere value ka idx at inorder ,index}
    vector<int> preorder, inorder;
    TreeNode* constructTree(int l,int r,int &idx){
        int sz=preorder.size();
        if(idx<sz){
            if(l<=r){
                TreeNode* node=new TreeNode(preorder[idx]);
                int position=M[node->val];
                idx++;
                TreeNode* leftChild=constructTree(l,position-1,idx);
                TreeNode* rightChild=constructTree(position+1,r,idx);
                node->left=leftChild,
                node->right=rightChild;
                return node;
            }
                
        }
        return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        
        3,9,20,15,7 pre
        9,3,15,20,7 in
        
        */
        this->preorder=preorder,
        this->inorder=inorder;
        int idx=0;
        for(auto it:inorder){
            M[it]=idx,
            idx++;
        }
        idx=0;
        return constructTree(0,preorder.size()-1,idx);
        
    }
};