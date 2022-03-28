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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {     
        pushAll(root);       
    }
    
    int next() {        
        TreeNode * temp= st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
        
    }
    //we are pushing all left side elements into stack so that when we wanna pop we will be popping eelements elements in inorder fashion.
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */