class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        /*
        
        abcde
        
        dsahjpjauf
        ahjpjau
        
        */
        int cnt=0;
        map<char,queue<string>> M;
        for(string str:words){
            M[str[0]].push(str);
        }
        
        for(char &ch:s){
            int sz=M[ch].size();
            for(int i=0;i<sz;i++){
                string top=M[ch].front(); 
                M[ch].pop();
                if(top.size()==1){
                    cnt++;
                }
                else{//top has size >1
                    M[top[1]].push(top.substr(1));
                }
            }
             
        }
        return cnt;
        
    }
};