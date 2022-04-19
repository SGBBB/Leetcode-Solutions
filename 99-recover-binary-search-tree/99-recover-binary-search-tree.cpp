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
    TreeNode *first=NULL;
    TreeNode *second=NULL;
    TreeNode *prev=new TreeNode(INT_MIN);
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        //logic application is started from here
        /*
        There might be 2 distortions 
        if we havent found first distortion and cur->val<prev->val 
        */
        if( !first  && root->val<prev->val ){
            first=prev;
        
        }
        /*
        this is the case when disturbance hapend between non-adjacent elements
        */
        if(first  and root->val < prev->val){
            second=root;
        }
        prev=root; //updating prev every time 
        //done with applying logic
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        /* there might be 2 cases:
        1. disturbance is happeneed among adjacent guys
        2. disturbance is happeneed among non-adjacent guys
        
        
        */
        // cout<<first->val<<endl;
        // cout<<second<<endl;
        swap(first->val, second->val);
    }
};