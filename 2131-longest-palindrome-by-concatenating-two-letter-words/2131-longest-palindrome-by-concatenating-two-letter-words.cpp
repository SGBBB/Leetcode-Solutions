class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /*
        
        I need the following :
        1. get the two letter word having max freq having both chars same
        2. if both chars of a word are different then find it reverse ans will be incremented by 4
        
        */
        
        
        unordered_map<string,int> M;
        for(auto it:words)
            M[it]++;
        int sameCharWordsFreq=0,centralPallindromicGuy=0,res=0;
        for(auto &it:M){
            string curStr=it.first;
            int curCnt=it.second;
            //if. both the chars are equal
             
            if(curStr[0]==curStr[1] ){
                if( curCnt&1 && centralPallindromicGuy==0 )
                    centralPallindromicGuy=2;
                sameCharWordsFreq+=(curCnt/2)*2*2;
                // cout<< centralPallindromicGuy<<"    "<<curStr<<" bc "<< ( (curCnt/2)*2*2 ) <<endl; 
            }
            else{
                string reverseString=curStr;
                reverse(reverseString.begin(),reverseString.end());
                if(M.count(reverseString) && M[reverseString]>0){
                    res+=min({M[reverseString],curCnt});
                    M[reverseString]=0;
                    
                }
                M[curStr ]=0;
            }
            
        }
        return sameCharWordsFreq +centralPallindromicGuy +
            res*2*2;
    }
};