class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxRepeating=0,maxLen=0,i=0,j=0,n=s.size();
        vector<int> cnt(26);
        while(j<n){
            cnt[s[j]-'A']++;
            if(cnt[s[j]-'A'] >maxRepeating ) maxRepeating=cnt[s[j]-'A'];//here Im updating my maxRepeating guy
            /*length of current substring -count of repeating characters <=k ( no of times operation is performed) */
            while( j-i+1-maxRepeating > k ){
                cnt[s[i]-'A']--;
                i++;
            }
            
            maxLen=max(maxLen , j-i+1);
            j++;
            cout<<maxRepeating<<endl;
        }
        return maxLen;

    }
};