// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{

     vector<int>ans;
  set<int>s;
  s.insert(-1);
  for(int i=0;i<n;i++)
  {
      s.insert(arr[i]);
      auto j = s.find(arr[i]); 
      j--;
    //   cout<< arr[i]<<" "<<*j <<endl;
      ans.push_back(*j);
  }
   return ans;
}