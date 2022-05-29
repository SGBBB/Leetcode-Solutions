class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cnt[26];
        memset(cnt,0,sizeof cnt);
        unordered_map<int ,int> M;
        
        for(auto &ch:s){
            cnt[ch-'a']++;
        }
        
        for(auto ch:target){
            M[ch-'a']++;
        }
        int min_cnt=101;
        for(auto it:M){
            int char_position=it.first;
            int char_cnt=cnt[char_position]/M[char_position];
            if(char_cnt<min_cnt)
                min_cnt=char_cnt;
            
            cout<<char_cnt<< " "<< min_cnt<<" "<< (char_cnt>min_cnt)<<endl;
        }
        /* if num of every guy is same then only one alphabet is preseent in multiple occurance
        I think some anagrams logic is applied here
        "ilovecodingonleetcode"
        "code"
        
        
        "abbaccaddaeea"
        "aab"
        
        */
        
        return min_cnt;
    }
};