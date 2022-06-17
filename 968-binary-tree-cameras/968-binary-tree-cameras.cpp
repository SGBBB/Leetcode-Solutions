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
    /*
    0( "needCamera" Im not monitored)
    1(  "noNeedCamera",      dont need camera Im already monitored)
    2(haveCamera)
    */
    int cnt;
    public:
    Solution(){
        this->cnt=0;
    }
    string dfs(TreeNode *root){
        if(root){
            string left=dfs(root->left),
                   right=dfs(root->right);
            // parent has a camera
            if(left=="needCamera" || right=="needCamera"){
                cnt++;
                return "hasCamera";
            }
                 
            //  parent doesn't needs a camera,he is protected
            else if( left=="hasCamera" || right=="hasCamera" )
                return "noNeedCamera";
            
            return "needCamera";
        }
        return "noNeedCamera"; // if there is NULL Node then we dont need camera
    }
public:
    int minCameraCover(TreeNode* root) {
        /*
        
        Consider every thing a slevel right 
        if either of the 2 choldren has a camera so curr node shouldnt own a camera
        
        
        */
        if(dfs(root)=="needCamera")
            return ++cnt;
        return cnt;
    }
};