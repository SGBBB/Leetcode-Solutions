// ackt 1
// act 0
// acit 1
struct Trie {
    Trie* ch[26] = {};
    bool end = false;
    void insert(string &s, int p = 0) {
        if (p < s.size()) {
            int idx = s[p] - 'a';
            if (ch[idx] == nullptr)
                ch[idx] = new Trie();
            ch[idx]->insert(s, p + 1);
        }
        else
            end = true;
    }
    bool find(string &s, int p = 0, bool wild = false) {
        // cout<< s[p]<<"  "<< p<< " "<< wild<< " end is "<<end << endl;
        if (p == s.size()){ 
            cout<<"reached end "<< " "<< s <<" "<<(wild & end)<<endl;
            //When p points to s.size() then my wild and end must be true 
            return wild && end;
        }
      
        int idx = s[p] - 'a'; 
        
        // cout<< s[p]<<"  "<< p<< " "<< wild<< "  end is "<< end<<endl;
        bool res=(ch[idx] != nullptr ? ch[idx]->find(s, p + 1, wild) : false) ||
            (wild ? false : find(s, p + 1, true)) ;
        /*
        
        find(s, p + 1, true) is calling to current level by marking wild true
        */
        
        return res;
    }
    
};
class Solution {
    public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    Trie t;
    for (auto &w : startWords) {
        sort(begin(w), end(w));
        t.insert(w);
    }
    int res = 0;
    for (auto &w : targetWords) {
        sort(begin(w), end(w));
        // cout<< w<<" "<<t.find(w) <<endl;
        // break;
        res += t.find(w);
    }
    return res;    
}

};