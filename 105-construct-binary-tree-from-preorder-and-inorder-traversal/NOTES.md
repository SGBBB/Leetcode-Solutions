```
class Solution {
map< int , int  > M;
TreeNode* helper(vector<int> &pre,vector<int> &in,int s,int e,int &rootIdx){
if(s>e) /*Base Case if either of the arrays are exhausted then return NULL */
{
return NULL;
}
int pivot=M[pre[rootIdx]];
cout<< " element is "<< rootIdx <<"pivot is "<<pivot <<endl;
TreeNode* node=new TreeNode(pre[rootIdx]);
rootIdx++;
TreeNode* L=helper(pre,in, s,pivot-1  ,rootIdx);
TreeNode* R=helper(pre,in ,pivot+1, e,rootIdx);
node->left=L;
node->right=R;
return node;
}
public:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
for(int i=0;i<inorder.size();i++)
M[inorder[i]]=i;
int rootIdx=0;
TreeNode* node= helper(preorder,inorder,0,preorder.size()-1,rootIdx );
return node;
}
};
```