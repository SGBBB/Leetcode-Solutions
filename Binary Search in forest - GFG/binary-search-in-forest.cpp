// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        int l=INT_MAX,h=INT_MIN,ans=-1;
        for(int i=0;i<n;i++)
            l=0,h=max(tree[i],h); 
        while(l<=h){
            int mid=(l+h)>>1; 
            int cnt=0;
            for(int i=0;i<n;i++){
                if(tree[i]>mid) cnt+=tree[i]-mid;
            }
            if(cnt==k) return mid;
            if(cnt>=k) 
                l=mid+1;
            else h=mid-1;
            
        }
        return -1;
    }
};
/*
What can be the max possible height
I believe there will always be some height 
such that is we divide every tree heights with that height  
then it will be equal to k


*/
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends