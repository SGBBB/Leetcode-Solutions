// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

bool cmp(char x,char y){
    // unordered_map<char,int> M={
	   //     {'!',1},{'#',2},{'$',3},{'%',4}, {'&',5} ,{'*',6} ,
	   //     {'@',7},{'^',8} ,{'~',9}
	        
	   // };
	   string hash="!#$%&*@^~";
	   int position1=hash.find(x), position2=hash.find(y);
    return position1<position2;
}
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    /*
	    !->1
	    #->2
	    $->3
	    %->4
	    &->5
	    *->6
	    @->7
        ^->8
        ~->9
	    
	    */
	    
	   // unordered_map<char,int> M={
	   //     {'!':1},{'#':2},{'$':3},{'%':4}, {'&':5} ,{'*':6} ,
	   //     {'@':7},{'^':8} ,{'~':9}
	        
	   // };
	   // int nuts_val[n],bolts_val[n];
	   // for(int i=0;i<n;i++){
	   //     nuts_val[i]=M[nuts[i] ] ,bolts_val[i]= M[bolts[i]];
	        
	   // }
	   // sort(nuts_val,nuts_val+n,cmp); sort(bolts_val,bolts_val+n,cmp);
	   sort(nuts,nuts+n,cmp); sort(bolts,bolts+n,cmp);
	   // for(int i=0,j=0;i<n and j<n;){
	   //     if(nuts_val[i]==bolts_val[j])
	   //     if(i<j) i++;
	   //     else if(j<i) j++;
	   //     else i++,j++;
	   // }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends