class Solution {
    
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={};
        for(char num:s)
            cnt[num-'a']++;
        for(char num:t){
            cnt[num-'a']--;
        
        }
        for(int i=0;i<26;i++){
            if(cnt[i]!=0)
                return 0;
        }
        return true;
    }
};