class Solution {
public:
    /*
    At every idx find whether its a valid spot or not
    1 ->odd occuring char freq
    0 ->even occuring char freq
    eleetminicoworoep
    1101
    ele
     leetminicowor
     
    This isnt east problem its bund todd problem
    */
    int findTheLongestSubstring(string s) {
        map<char,int> freq;
        int n=s.size();
        int i=0,j=0,maxLen=0,cur=0;
        freq.insert({0, -1});
        string str="aeiou";
        for(int i=0;i<n;i++){
            int pos=str.find(s[i]);
            //if cur char is a vewel then do xor 
            
            if(pos>-1 && pos<5){
                cur^=1<<pos;
            }
            if(!freq.count(cur)){
                freq[cur]=i;
            }
            maxLen=max({maxLen,i-freq[cur]});
        }
        
        return maxLen;
    }
};