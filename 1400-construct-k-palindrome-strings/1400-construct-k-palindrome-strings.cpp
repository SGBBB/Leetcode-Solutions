class Solution {
public:
    bool canConstruct(string s, int k) {
        int len=s.size();
        if(len<k) return false;
        if (len==k) return true;
        //now len is greater than k
        vector<int> frequency(26);
        for(char ch:s) frequency[ch-'a']++;
        int cnt=0;
        for(int i:frequency){
            if(i){
                cnt+=(i&1);
            }
        }
        return  cnt<=k;
    }
};