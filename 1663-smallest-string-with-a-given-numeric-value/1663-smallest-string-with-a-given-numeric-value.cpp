class Solution {
public:
    string getSmallestString(int n, int k) {
        // cout<<('k'-'a'+1)<<endl;
        // return "kkk";
        string ans=string(n,'a') ; //created a string having all chars asa bydeault 'a'  and parallely subtracted value of 'a'*n from k;
        k-=n;
        /* if k is 0 then just return ans */
        
        if(!k) return ans;
        
        // now k >0 so i'll travel string from end an do processing.  
        for(int i=n-1; k>0;i--){
            k+=ans[i]-'a'+1; //k is creadited with value of  'a' .
            // cout<<" k is "<<k<<" "; 
            // cout<<char('a'+k-1) << endl;
            if(k>=26) ans[i]='z',k-=26;
            else ans[i]='a'+k-1,k=0;
            
            
        }
        
        return ans;
    }
};