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
    unordered_map<int,int > M; 
public:
    int pathSum(TreeNode* root, int targetSum ,int gain=0,int cnt=0) {
        if(root){
           gain+=root->val;
           cnt+=(gain==targetSum) ;
            if( M[gain-targetSum]>0)
                {cnt+=M[ gain-targetSum ]; 
                cout<< gain<<"kitnin bar "<< root->val ;
                cout<<" "<< M[ gain-targetSum ]<<endl;
                }
            M[gain ] ++;
            cnt+=pathSum(root->left,targetSum,gain ,0)+
                pathSum(root->right,targetSum,gain,0);
            M[gain]--;
            // if(root->val==11 ) cout<<gain<< M[gain]<<endl;
            return cnt; 
            
        }
    return 0;
    }
    
};