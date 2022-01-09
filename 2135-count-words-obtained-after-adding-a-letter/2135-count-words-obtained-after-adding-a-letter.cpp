// struct Node{
//     Node* arr[26];
//     int flag=0;
    
// };
// Node* root=new Node();
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
        if (p == s.size())
            return wild && end;
        int idx = s[p] - 'a'; 
return (ch[idx] != nullptr ? ch[idx]->find(s, p + 1, wild) : false) || (wild ? false : find(s, p + 1, true));
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
        cout<< w<<" "<<t.find(w) <<endl;
        res += t.find(w);
    }
    return res;    
}
//     int alphabets="abcdefghijklmnopqrstuvwxyz";
//     void insert_node(string word){
//         Node* node=root;
//         for(char ch:word){
//             if(!node->arr[ch-'a'] )
//                 node->arr[ch-'a']=new Node();
//             node=node->arr[ch-'a'];
//         }
//         node->flag=1;
//     }
//     bool find_nodes(string word){
//         // vector<bool> visited(26,false);
//         queue<string>  q(word.begin() ,word.end() );
//         int rotations=0;
//         Node* node=root;
//         while(q.size() and rotations<q.size() ){
//             char ch=q.front(); q.pop();
//             for(char letter:alphabets ){
//             if(  letter==ch and   node->arr[ch-'a'] )
//                 node=node->arr[ch-'a']; //updation
//             else 
//         }
            
//         }
        
        
//         return node->flag;
//     }
    
// public:
//     int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
//         root=new Node();
//         for(auto word:startWords){
//             insert(word);  
//         }
//         int cnt=0;
//         for(auto word:targetWords){
//             cnt+=find(word);
//         }
//         return cnt;
//     }
};