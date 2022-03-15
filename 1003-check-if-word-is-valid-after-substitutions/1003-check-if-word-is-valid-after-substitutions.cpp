class Solution {
public:
    bool isValid(string s) {
       //  int cnt=0;
       //  string pattern="abc";
       //  int frequency[3]={};
       //  for(char ch:s){
       //      int pos=pattern.find(ch);
       //      cout<<pos<<endl;
       //      frequency[pos]++;
       //      if( ch=='a' ) cnt++;
       //      else if( frequency[pos-1]<frequency[pos] ) return 0;
       //      else if(ch=='c') cnt--;
       //  }
       // return !cnt; 
        //Shit forst solutioin didnt killed all the  testcases here is my another approach
       // stack<char> st;
       //  for(char ch:s){
       //      int flag=0;
       //  if( !st.empty() and
       //  ((st.top()=='a' and st.top()=='b'  ) or (  st.top()=='b' and st.top()=='c'  )) ){ 
       //     st.pop()  ,flag=1 ;
       //     }
       //     // if(!flag)
       //      st.push(ch);
       // }
       //  return st.empty();
        int cnt[3]={};
        string ans="";
        for(char ch:s){
            cnt[ch-'a']++;
            int n=ans.size();
           if( ch=='c' and n>1  and ans.back()=='b' and ans[n-2] )    
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