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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map< int ,TreeNode* > M;
        unordered_map< int  ,bool> has_parent;
        for(auto it:descriptions){
            if(!M.count(it[0] )) 
                M[it[0] ] =new TreeNode(it[0]);
            if(!M.count(it[1]) )
                M[it[1]]=new TreeNode(it[1]);
            if(it[2]==1){
                //mark the left child
                M[it[0]]->left=M[it[1]];
            }
            else{
                M[it[0]]->right=M[it[1]];
            }
            // if( !has_parent.count(it[0]) )
            //     has_parent[it[0]]=0;
            has_parent[it[1]]=1;
        }
        for(auto it:M){
            //I found the guy. with no parent is witnessed then return it it is the root of the tree
            if( !has_parent.count(it.first) ) return it.second;
        }
        return NULL;
    }
};

/*
Problem seens easy 
but how will i go about solving this??

*/