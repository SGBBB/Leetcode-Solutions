class Solution {
    string formulate(string str){
        
        string ans;
        unordered_map<char ,char> M;
        char num='1';
        for(auto it:str){
            if(!M.count(it)){
                M[it]=num;
                  
                num++;
            }
            //This statement will only be executed when M[it] is having some value
                ans+=M[it];
            
        }
        return ans;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        /*
        
        ABBAA
        abbaa
        abbaa
        
        abb
        122
        
        abc
        123
        
        deq
        123
        
        mee
        122
        
        aqq
        122
        
        dkd
        121
        
        ccc
        111
        
        */
        pattern=formulate(pattern);
        vector<string> res;
        for(string str:words){
             
            //iterating through each word
             
            if(pattern==formulate(str)){
                res.push_back(str);
            }
                
        }
        
        return res;
        
    }
};