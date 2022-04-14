/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode* ,TreeNode *> M;
    void markParents(TreeNode* root){
        if(!root) return ;
        if(root->left) {
            M[root->left]=root;
            markParents(root->left);
        }
        if(root->right){
           M[root->right]=root;
           markParents(root->right); 
        }        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root )return ans;
        markParents(root);
        map<TreeNode* ,int> visited;
        queue<TreeNode*> q;
        q.push(target);        
        visited[target]=true;
        while(q.size()>0){
            /*breaking once k==0*/ 
            // if(!k ) cout<< q.front()->val <<endl;
            if(!k) break;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto p= q.front();
                visited[p]=true;
                q.pop();
                if(M.count(p)   and !visited[M[p]]){
                    q.push(M[p]),
                    visited[M[p]]=true;
                    
                }
                if(p->left and !visited[p->left]) {
                    q.push(p->left),
                    visited[p->left]=1;
                }
                if(p->right and !visited[p->right]) {
                    q.push(p->right),
                    visited[p->right]=1;;
                }
            }
            k--;
        }
        while(q.size()>0){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};