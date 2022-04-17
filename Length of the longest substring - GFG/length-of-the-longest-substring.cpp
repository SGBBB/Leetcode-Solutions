// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        vector<int> cnt(26,-1);
        int maxLen=1;
        int i=0,j=0;
        while( j<S.size()){
            // cout<< (cnt[S[j] -'a'])<<endl;
            //im doing cnt[S[j]-'a'] + 1 becoz i will start my new journey after 
            //last found position +1
            i=max({ i , cnt[S[j] -'a' ] + 1 }),
            maxLen=max({ maxLen, j-i+1  }),
            cnt[S[j]-'a']=j,
            j++;
        }
        
        return maxLen;

        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends