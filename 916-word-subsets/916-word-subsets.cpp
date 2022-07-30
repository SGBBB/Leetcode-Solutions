class Solution {
   /*
   
   leetcode
   eo
   do
   eed
   
   equivalent-> eeod
   
   
   */ 
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {    
        /*
        Collection of words2 must be in aggregate 
            unordered_map
        
        */
        unordered_map<char ,int> M_words2;
        for(auto str:words2){
            unordered_map<char ,int > tempMap;
            for(char ch:str){
                tempMap[ch]++;
            }
            
            for(auto it:tempMap){
                if(it.second>M_words2[it.first]){
                    M_words2[it.first]=it.second;
                }
            }
        }
        vector<string> res;
        for(auto it:words1){
            unordered_map<char,int> M_words1;
            // mapping frequency of each word
            for(char ch:it){
                M_words1[ch]++;
            }
             
               
            // checking whether each string of words1 is super-set of words2
            int flag=0;
            for(auto it:M_words2){
                char ch=it.first;
                int cnt=it.second;
                if(cnt>M_words1[ch])
                    break;
                flag++;
            }
            // cout<< flag <<endl;
            if(flag==M_words2.size())
                res.push_back(it);
            
        }
        return res;
    }
};