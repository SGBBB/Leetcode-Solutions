class Solution {
    
        
public:
    bool validPalindrome(string s) {
        // cout<<s.size()-1<<endl;
        return isValid(s,0,s.size()-1);
    }
    bool isValid(string &s,int i,int j,bool can_del=true){
        // cout << "i. and j are  "<<i<< " "<<j<<endl;
        if(i>=j) return 1;
        
            if(s[i]==s[j]  ) return isValid(s,i+1,j-1,can_del);
            //Now s[i]!=s[j] 
                if(!can_del)
                    return 0;  
            return isValid(s,i+1,j,0) || isValid(s,i,j-1,0);
            
    }
};

/*
"ee c   c c cbebaeeabeb c c   c eea"
"   eeccccbebaeeabebccceea "
if given string is already a palindrome then its ok return true indeed!
i think its not necessary to deletee a char 
but if we delete we can delete not more than 1 char 
let me think aboiut ithrt test cases
aacav
eeccccbebaeeabebccceea
xaaac
abcd
adpopaa
we use two pointers one placed at left other placed at right (n-1  pe )
we do i++,j-- until we reach a point when s[i]!=s[j]
at this moment two cases arise
1. delete left guy and test whether left+1 till right is pallindromic
2. is string pallindromic after deleting right guy
*/