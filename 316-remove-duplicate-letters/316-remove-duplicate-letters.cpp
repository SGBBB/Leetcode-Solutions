class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26);
        for(char ch:s){
            freq[ch-'a']++;
        }
        vector<bool> vis(26,false);
        stack<int> st;
        for(int i=0;i<s.size();i++){            
            char ch=s[i];            
            if( vis[ch-'a'] ) {  freq[ch-'a']--;  continue;}
            vis[ch-'a']=true;
            while(st.size() and s[st.top()]>ch and freq[s[st.top()]-'a']>1 ){
                freq[s[st.top()]-'a']--;
                vis[s[st.top()]-'a']=false;
                st.pop(); 
            }
            st.push(i);
        }        
        string res;
        while(st.size() ){
            res=  s[st.top() ]+ res ;
            st.pop();
        }
        
        return res;
    }
};