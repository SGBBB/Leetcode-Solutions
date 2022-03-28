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
    int helper(TreeNode* root,int k,int &cnt){
        if(!root) return 0;        
        int L=helper(root->left, k, cnt);
        cnt++;
        if(cnt==k) return root->val;
        //if i have got something from node->left then return it this will prevent us to unecessary visit right child
        if(root->left &&  L!=0) return L;
        int R=helper(root->right,k,cnt);
        int res=0;
        //This snippppet is to check whether you have received any node number from either child , if received any node value beside 0 so consider returning it to ancestor
        if(root->left and L  ) res=L;  
        if(root->right and R ) res=R;
        return res;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int  cnt=0;
        return helper(root, k, cnt);
        
    }
};