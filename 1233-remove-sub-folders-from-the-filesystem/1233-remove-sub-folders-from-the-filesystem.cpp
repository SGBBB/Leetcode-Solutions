struct Node{
    Node* arr[26];
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder.front());
        for(int i=1,n=folder.size();i<n;i++){
            string root=ans.back()+"/"; cout<<root<<endl;
            if( folder[i].substr(0,root.size() ) != root )                                  ans.push_back(folder[i]);
        }
        return ans;
    }
};