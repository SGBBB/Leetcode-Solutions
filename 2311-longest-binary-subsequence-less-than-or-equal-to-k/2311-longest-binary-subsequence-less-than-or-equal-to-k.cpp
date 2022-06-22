using ll=long long;
class Solution {
public:
    int longestSubsequence1(string s, int k) {
         
         
        int sz=s.size() ,power=0,cnt_one=0,value=0 ;
        int i=sz-1;
        for(;i>=0 && (value+ (1<<power)*(s[i]-'0') )<=k;i--){
            int digit=s[i]-'0';
            // if I can tadd more zeroes then just do continue;
            if(   digit==1   ){
                value+=  (1<<power) ;
                cnt_one++;
                cout<<cnt_one<<endl;
                
            }
                
            
            
             
                
            power++;
            
             
        }
        // cout<<i<<endl;
        int cnt_zero=0;
        for(auto it:s)
            cnt_zero+=(it=='0');
        return cnt_one+cnt_zero;
    }
    
    int longestSubsequence(string s, int k) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int cnt=0;//count will maintain our answer and will also help in calculating what next value we will add in our val when next '1' comes because we also want index.
        int val=0;
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            if((num*pow(2,cnt)+val)<=k){
                val=val+num*pow(2,cnt);
                cnt++;
            }
        }
        
        return cnt;
    }
};