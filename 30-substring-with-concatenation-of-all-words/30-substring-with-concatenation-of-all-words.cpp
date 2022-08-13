class Solution {
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int > M;
        vector<int> ans;
        for(string str:words){
            M[str]++;
        }
        
        int i=0,j=0,n=s.size(),windowLen=words.size() *words[0].size(),
        wordLen=words[0].size();
        for(int i=0;i<n-windowLen+1;i++){//testing for all every ith place
            int j=i;
            unordered_map<string, int > holder=M;
            while(j<min(i+windowLen,n)){
                string substring=s.substr(j,wordLen);
                if(holder.count(substring)){
                    holder[substring]--;
                    if(holder[substring]==0) 
                        holder.erase(substring);
                    j+=wordLen;
                }
                else
                    break;
            }
            if(holder.empty()) 
                ans.push_back(i);
        }

        return ans;
    }
};

/*
"barfoothefoobarman"  ["foo","bar"]
foobar,barfoo



"wordgoodgoodgoodbestword"

"barfoofoobarthefoobarman"


Observation:

What my brain says let's put words in map
becoz there is no way to make combinations of words.
i think it's fixed size sliding window problem.
becoz every time we are taking words.size() *words[0].size() size window


*/