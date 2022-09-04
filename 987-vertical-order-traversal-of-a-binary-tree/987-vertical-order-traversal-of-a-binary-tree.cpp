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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /*using BFS Solution*/
        map< int ,map < int, multiset<int> >> M;
        queue< pair<TreeNode* ,pair<int,int>>  > q;
        q.push({root,{0,0}});
        while(q.size()){
            auto p=q.front();           
            TreeNode* node=p.first;            
            q.pop();
            int x=p.second.first;
            int y=p.second.second;
            M[x][y].insert(node->val);
            if(node->left)  q.push({node->left ,{x-1 , y+1}});
            if(node->right) q.push({node->right, {x+1, y+1 }});
                        
        }
        
        vector<vector<int> >  ans;
        for(auto i:M){
            vector<int> temp;
            for(auto j:i.second) {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};