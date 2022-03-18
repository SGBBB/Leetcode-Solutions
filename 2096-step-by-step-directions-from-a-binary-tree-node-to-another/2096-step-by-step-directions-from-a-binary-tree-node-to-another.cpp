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
    bool find(TreeNode *root, int value, string &path){
        if(!root) return false;
        if(root->val==value) return true;
        //Either Im  receiving value from the lelft side or from the right side base on my verdict i'll return true from either side. 
        path+='L';
        if( find(root->left, value ,path) )
             return true;
        else path.pop_back();
        path+='R';
        if( find(root->right , value , path ) )
            return true;       
        else path.pop_back();
        return  false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_path,d_path;
        find(root, startValue, s_path);
        find(root, destValue ,d_path );
        cout<< s_path<< "" << d_path<<endl;
        while( s_path.size() and d_path.size() and s_path.front()==d_path.front()  ){
            s_path.erase(s_path.begin()); 
            d_path.erase(d_path.begin());
        }
        
        return string(s_path.size() ,'U') + string(d_path.begin() , d_path.end() );
    }
};