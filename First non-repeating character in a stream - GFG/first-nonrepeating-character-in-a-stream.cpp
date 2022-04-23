// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int cnt[26];
		    memset(cnt,0,sizeof cnt);
		    deque<char > dq;
		    string ans="";
		    int idx=0;
		    for(char ch:A){
		        ++cnt[ch-'a'];
		      //  if(idx==1) cout<< ch<<" behen ke lode " <<cnt[dq.front()-'a']<<" "<<dq.front() <<" ";
		        if( cnt[ch-'a']==1 )
		            dq.push_back(ch);
		        //This while loop will execute at max 26 times
		        while(dq.size() && cnt[dq.front()-'a']>1){
		            dq.pop_front();
		        }
		      //  cout<< idx<<" madar "<<dq.size() <<endl;
		        
		        if(dq.empty() ) ans+='#';
		        else{  ans+=dq.front();}
		        idx++;
		    }
		    return ans;
		}
		
		/*
		aabc
		a#b
		
		
		
		
		
		
		
		
		
		
		
		
		
		https://ideone.com/Re4Ite
		*/

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends