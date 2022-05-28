struct Node{
    Node* arr[26];
};

/*
"/a/b/c"   "/a/b/ca"   "/a/b/d"
"/a"       "/a/b"       "/c/d"       "/c/d/e"       "/c/f"
"/a/b/g"  "/a/g"
1.Post sorting the next string is gonna be bigger than current string.



*/

class Solution {
public:
    vector<string> removeSubfolders_another_method(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder.front());
        for(int i=1,n=folder.size();i<n;i++){
            string root=ans.back()+"/"; cout<<root<<endl;
            if( folder[i].substr(0,root.size() ) != root )                                  ans.push_back(folder[i]);
        }
        return ans;
    }
    
    vector<string> removeSubfolders(vector<string>& folder){
        int n=folder.size();
        sort(folder.begin(),folder.end());
        
        vector<string> ans;
        string temp="";
        for(vector<string> :: iterator it=folder.begin() ;it!=folder.end();it++){
            if( it==folder.begin()  || temp.size()>(*it).size() ){
                ans.push_back(*it),
                temp=*it;
                continue;
            }
            int sz=temp.size();
            string cur=*it;
            if(temp==cur.substr(0,sz) && cur[sz]=='/'){
                continue;
            }
            ans.push_back(*it),
            temp=*it;
            
            
        }
        for(auto it:folder)
            cout<< it  <<endl;
        return ans;
    }
};