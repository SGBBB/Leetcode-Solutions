class Solution {
    int minUnfairness=INT_MAX;
    void dfs(vector<int>& cookies, int k,vector<int> &cookiesDistribution,int idx ){
        //At every idx Ihave got 8 choices at max 
        // So Overall Complexity is gonna be k^n 
        // cout<<"idx   " <<idx  <<endl;
        if( idx==cookies.size() ){
    
            //Perform tasks
            int largeAns=0;
            for(int i=0;i<k;i++){
                int curChildCookieCnt=cookiesDistribution[i];
                largeAns=max( {largeAns,curChildCookieCnt} );
            }
            // cout<<largeAns<<endl;
            minUnfairness=min({minUnfairness,largeAns});
            return;
        }
        for(int i=0;i<k;i++){
            cookiesDistribution[i]+=cookies[idx];
            dfs(cookies,k,cookiesDistribution,idx + 1);
            //undo step
            cookiesDistribution[i]-=cookies[idx];
            if(!cookiesDistribution[i])
                break;
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> cookiesDistribution(10);
        dfs(cookies,k,cookiesDistribution, 0);
        return minUnfairness;
    }
    
    /*
    
    [8,15,10,20,8]
    8
    15 
    10
    20
    8
    
    */
// public:
     
//    int maxi=INT_MAX;
//     void explore(vector<int>&cookies,int n,int k,vector<int>&vec)
//     {
//       if(n==cookies.size())
//       {
//           int m=0;
//           for(int i=0;i<k;i++)
//           {
//               m=max(m,vec[i]);
              
//           }
//           maxi=min(maxi,m);
//           return;
//       }
//         for(int i=0;i<k;i++)
//         {
//             vec[i]+=cookies[n];
//             explore(cookies,n+1,k,vec);
//             vec[i]-=cookies[n];
//         }
//     }
    
       
//     int distributeCookies(vector<int>& cookies, int k) {
      
//         vector<int> vec(10,0);
//           explore(cookies,0,k,vec); 
//         return maxi;
        
//      }
};
