class Solution {
public:
    bool detectCapitalUse(string word) {
        bool condition1=0,condition2=0,condition3=0;
        int len=word.size(),cnt1=0,cnt2=0;
        for(char ch:word){
            cnt1=isupper(ch)?cnt1+1:cnt1,
            cnt2=islower(ch)?cnt2+1:cnt2;
        }
        condition1=cnt1==len?true:0,
        condition2=cnt2==len?true:0,
        condition3=( isupper( word.front() ) and cnt2==len-1  )?1:0
        ;
        return condition1 or condition2 or condition3;
    }
};