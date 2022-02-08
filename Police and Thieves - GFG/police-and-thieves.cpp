// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        vector<int> police,thief;
        int i=0,j=0;
        char ch;
        for(;i<n; i++ ){
            ch=arr[i];
            if(ch=='P'){
                police.push_back(i);
            }
            else thief.push_back(i);
        }
        int n1=police.size() ,n2=thief.size(), cnt=0;
        // cout<<"n1 and n2 are  "<<n1<<" "<<n2<<endl;
        //i can catch thieves from ither sides of poice
        for(i=0,j=0;i<n1 and j<n2 ;){
            if(abs(police[i]-thief[j]  ) <=k ) cnt++,i++,j++;
            else if( police[i]< thief[j]   ) i++;
            else j++;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends