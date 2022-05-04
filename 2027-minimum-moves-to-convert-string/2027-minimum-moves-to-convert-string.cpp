class Solution {
public:
    int minimumMoves(string s) {
        int cnt=0;
        for(int i=0;i<s.size();){
            cnt=cnt+(s[i]=='X');
           if(s[i]=='X') i+=3;
           else i++;
        }
        return cnt;
    }
};

/*
XOXXXO
XOXXOX
XXOXOXOXXX
XXOXXX
*/
