class Solution {
public:
    bool isValid(string s) {
        int cnt[3]={};
        string ans="";
        for(char ch:s){
            cnt[ch-'a']++;
            int n=ans.size();
           if( ch=='c' and n>1  and ans[n-1]=='b' )    
               {
               cnt[0]--,cnt[1]--,cnt[2]--;ans.pop_back();ans.pop_back() ;
               cout<<"o bencho"<<endl;
               }
            else
                ans.push_back(ch);
            // if(ch=='c')
            // cout<<ans<<cnt[0]<< cnt[1]<< cnt[2]<<endl;
         }
        
        
        return !(abs(cnt[0])+abs(cnt[1])+abs(cnt[2]));
    }
};

/*

ababcc


intuition is "abc" collectively form an atom which we can break once its encountered.

*/