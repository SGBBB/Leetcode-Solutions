class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        string res;
        for (auto ch : s) {
            //some business logic
            /* 
            
            "abbbaa"
            3
            
            */  
            if(!st.empty()  && st.back().first==ch){
                if( ++st.back().second==k ) //everytime im incresing the cnt if st.back char is equivalent to ch
                    st.pop_back();
            }
            else 
                st.push_back({ch,1});
            //if you met a new  char then do ots fresh entry with occurance 1.
              
        }
        for(auto it:st){
            //everytime creating a new string and appending to existing res;
            res+=string(it.second,it.first);
        }
        return res;
    }
};
/*
How will I move ahead int his problelm??????


        "deeedbbcccbdaa"
        initially remove k duplicates ,you will receive a new string pass it to the recursive function 
        
        
        
    This whole process is gonna take O(n^2) complexity.
    "deeedbbcccbdaa"->"ddbbbdaa"->"dddaa"->"dddaa"=>"aa" this is my final ans.
    One clue is clear that s only contains lower case English letters.
    How can you leverage this fact?????
    Can you use stack data structure to solve this problem upto some extent.
    
    "deeedbbcccbdaa"
    
    
*/