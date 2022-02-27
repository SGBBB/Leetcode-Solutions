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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res=0;
        if(!root)return res;
        queue<pair<TreeNode*,int >> q;
        q.push({root,1}); 
        unsigned long long l,r;
        while(q.size()){            
            unsigned long long len=q.size();
            cout<<endl<<"\n len is"<<len <<endl;
            r=q.front().second; 
            l=r;
            for(int k=0;k<len;k++){
                TreeNode* temp=q.front().first;
                r=q.front().second; 
                q.pop();
                if(temp->left){
                    q.push({temp->left , 2*r});                                  
                }                    
                if(temp->right) q.push({temp->right , 2*r+1});
            }
            res=max(res, r-l+1);             
        }
        
        return (int)res;
    }
};