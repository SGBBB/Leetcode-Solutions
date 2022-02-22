class Solution {
public:
    int titleToNumber(string columnTitle,int i=0) {
        int  ans=0;
        for(char ch:columnTitle){
            ans*=( 26 ), ans +=(ch-'A'+1);
        }
        return ans;
    }
};