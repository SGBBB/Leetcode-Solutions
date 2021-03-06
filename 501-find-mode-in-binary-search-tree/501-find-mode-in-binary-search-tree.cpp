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
    int cnt=1,max_frequency=0,pre=INT_MIN;
    vector<int> ans;
public:
    vector<int> findMode(TreeNode* root) {
        
        //do inorder  traversal then  check whether pre is equivalent to cur if yes increment cnt 
        int cur=root->val;
        if(root->left) //if root ->left is not null then only go to its left subtree
            findMode(root->left);
        //preocessing started
        if(cur!=pre){
            
            pre=cur;//update pre every time if its not equal to cur
            cnt=1; 
        }
        else cnt++;//if cur==pre then do cnt++;
        // cout<<cnt<<max_frequency<<" node "<<root->val<<endl; 
        if(cnt>max_frequency) {
                ans.clear();
        //if cnt>mode then remove already sitting elements inside ans vector
                ans.push_back(cur),
                max_frequency=cnt;
            }
            else if(cnt==max_frequency){
                ans.push_back(cur);
                
            }
        //processing finished
        if(root->right) //if im having right child then only visit towards right subtree
        findMode(root->right);
        
        return ans;
    }
};