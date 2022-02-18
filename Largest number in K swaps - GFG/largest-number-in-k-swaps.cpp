// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    void MaximumNumber(string &str,string &ans,int k,int idx=0){
        int len=str.size();
       if(k>0){
           int start=idx+1;
           int max_digit_value=str[idx];
           for(;start<len;start++){
               if(str[start]>max_digit_value)
               max_digit_value=str[start];
           }
           
           
           //choice of k
           k=( str[idx]!=max_digit_value ) ? k-1: k;
        //   return findMaximumNum(str,k,idx+1);
        
        for(int i=idx;i<len;i++){
            if(str[i]==max_digit_value){
                swap(str[i],str[idx]);
                if(str>ans)
                ans=str;
                MaximumNumber(str,ans,k,idx+1);
                swap(str[i],str[idx]);
                
            }
        }
        
        
       }
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string &str, int k)
    {
        string ans;
       MaximumNumber(str,ans,k);  
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends