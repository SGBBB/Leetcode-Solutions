class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0,n=s.size(),len=p.size();
        if(s.size() < p.size())
           return {};
        vector<int> frequency(26,0),temp(26,0);
        vector<int> ans;
        for(;j<len;j++){
            //logic
            frequency[p[j]-'a']++;
            temp[s[j]-'a']++;
            // cout<<endl;
        }
        //check
        if(temp==frequency) ans.push_back(i);
        for(;j<n;i++,j++){
            //logic
            if(temp[s[i]-'a']>=0)
                temp[s[i]-'a']--;
            temp[s[j]-'a']++;
            if(temp==frequency) ans.push_back(i+1);
            
        }
        return ans;
    }
};