class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        vector<int> frequency(26),curr_frequency(26);
        for(char ch:s1) frequency[ch-'a']++;
        int i=0,j=0;
        for(;j<n1;){
            curr_frequency[s2[j++]-'a']++;
        }
        if(curr_frequency==frequency) return true;
        for(;j<n2;){
            curr_frequency[s2[i++]-'a']--,curr_frequency[s2[j++]-'a']++;
            
            if(curr_frequency==frequency) return true;
        }
        return false;
    }
};