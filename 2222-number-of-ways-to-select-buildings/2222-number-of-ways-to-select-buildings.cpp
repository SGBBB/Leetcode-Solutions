class Solution {
public:
    long long numberOfWays(string s) {
        long long left0=0,left1=0,right0=0,right1=0,idx=0,n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            right0+=s[i]=='0',
            right1+=s[i]=='1';
        }
        for(int i=0;i<n;i++){
             if(s[i]=='0'){
                 
                 
                ans+=left1*right1;
                 right0--,left0++;
             }
            else{ //cur char is 0
                
                
                ans+=left0*right0,
                right1--,left1++;
            }
        }
        return ans;
    }
};