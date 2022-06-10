class Solution {
public:
    int longestPalindrome(string s) {
        /*
        Seems like a typical 2 pointer problem
        one pointing to the start another pointing to the end of the string
        
        abccccdd
        
        Should I check in every window
        
        
        Didnt understand the problem statement correctly
        
        
        Observations:
        If char's are present in even occurance then its a booon
        half we will place one side and other half to the other end
        What if some chars are present in odd occurances
        dcc b(ab)b ccd
        
        
        Algo:
        1.cnt the occurances of every char
        2.if some guy is having odd occurances except >1 then
          do cnt-1 then its gonnna become even 
        3.
        
        
        
        */
        vector<int> frequency(106);
        int pallindromelength=0;
        //storing frequency of every char
        // cout<<('A'-'a')<<endl;
        for(auto ch:s){
            frequency[ch-'a'+32 ]++;
        }
        bool hasCharCntOne=0;
        for(int i=0;i<106;i++){
            int charCnt=frequency[i];
            // If charCnt happens to be 0 then ignore it
            if(!charCnt)
                continue;
            
            // If the charCnt is even
            if( !( charCnt&1 ) ){
                pallindromelength+=( charCnt>>1 );
            }
            // If the charCnt is odd
            else{
                // If the charCnt is 1 then I'm having a char with occurance 1
                if(charCnt==1){
                    hasCharCntOne=1;
                    continue;
                }
                // Now charCnt has become odd
                charCnt=charCnt-1;
                pallindromelength+=( charCnt>>1 );
                hasCharCntOne=1;
            }
                
        }
        
        return pallindromelength*2  + hasCharCntOne ;
    }
};