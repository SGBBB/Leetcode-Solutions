
class Solution {
    
public:
    char findTheDifference(string s, string t) {
        string str=s+t;
        int ans=0;
        for(char ch:str){
            
            ans^=ch;
            cout<<ans <<endl;
        }
        
        return (char)ans;
    }
};