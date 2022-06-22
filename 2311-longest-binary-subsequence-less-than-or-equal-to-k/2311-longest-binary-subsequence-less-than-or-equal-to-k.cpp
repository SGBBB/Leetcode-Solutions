class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size(),value=0 ,power=0,max_len=0;
        for(int i=n-1;i>=0;i--){
            int num=s[i]-'0';
            
            if( value+pow(2,power)*num <=k ){
                value+= pow(2,power)*num;
                power++;
                max_len++;
            }    
        }
        return  max_len ;
    }
};