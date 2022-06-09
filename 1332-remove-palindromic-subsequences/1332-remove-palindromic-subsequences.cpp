class Solution {
public:
    /*
    Should think in reverse manner constructing string frmo empty to healthy palliondromic string
    
    ababa
    In worst case ,consider all single char as pallindromes
    maximum no of pallindromes -> a,b,a,b,a
    
    
    baabb
    baab
    
    
    baabb 
    baab b
    
    Is there difference btw subseq and subbstring if only 2 letters are present ???
    
    abba 
    I know there are 4 pallinromic subseq on total
    but how will I know minimum pallindromes
    
    abbabbaa
    
    
    */
    int removePalindromeSub(string s) {
        if(s.empty() )
            return 0;
        bool isPallindrome=1;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                isPallindrome=0;
            i++,j--;
        }
        if(isPallindrome)
            return 1;
        return 2;
    }
};