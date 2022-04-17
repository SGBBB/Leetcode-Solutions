class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> M;
        int n1=t.size(), n2=s.size(),i=0,j=0,minLen=INT_MAX,minStart=0,cnt=n1;
        if(n1 > n2) return "";
        for(char  ch:t){
            M[ch]++;            
        }        
        while(j<n2){
            if(M[s[j]]>0) cnt--;
            M[s[j]]--;
            // j++;
            while(cnt==0){
                if(j-i+1<minLen){
                    minLen=j-i+1 ,
                    minStart=i;
                }
                M[s[i]]++;
                if(M[s[i]]  >0 ){/*if the character is required then it will automatically go greater than 0*/
                    cnt++;
                }
                i++;
            } 
        j++;
        }        
        return (minLen==INT_MAX)?"":s.substr(minStart,minLen);
    }
};