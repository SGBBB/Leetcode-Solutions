class Solution {
public:
    string removeKdigits(string num, int k) { 
        string ans="";
        for(char ch:num){
            for(;ans.size() and ans.back()>ch and k>0;ans.pop_back() ,k--  ){}
            if( ans.size() or ch!='0' ) ans.push_back(ch); 
            // cout<<ans<<endl;
        } 
        for(;ans.size() and k>0 ;ans.pop_back() ,k--){} 
        // cout<<ans.size()<<" "<<ans<<endl;
        return (ans.size() )?ans:string("0");
    }
};