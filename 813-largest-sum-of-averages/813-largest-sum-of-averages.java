
class Solution {
    /*
    [9 1 2 3  ]  k = 3
    wht choices do I have at every step?????
    
    [1,2,3]
    2
    
    */
    
     double 
         solve(vector<int>& nums, int k,int start,vector <vector <double>> &visitedStates){
        if(k<1 )
            return 0.00;
         cout<<k<<" "<<start<<endl;
        if(visitedStates[k][start]!=-1.00)
            return visitedStates[k][start];
        double sum=0.00,
               maxScore=0.00;
         
        // logic
        for(double idx=start,n=nums.size();idx<=n-k ;idx++){
            sum+=nums[idx];
            
            // Call function again only when k>1,
            //if k==1 then consdier remaining guys as one subarray
            //or if Im at 0th idx then 
            
            if(k>1 || idx==n-1 ){
                
                //Sum from k-1 subarrays
                double k_1Score=solve(nums,k-1,idx+1,visitedStates);
                //CurScore
                double curScore=(sum)/(idx-start+1) + k_1Score;
                
                maxScore=max(maxScore,curScore);
            }
            
        }
         return visitedStates[k][start]=maxScore;
         
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k ) {
        vector <vector <double>> 
            visitedStates( nums.size() + 1, vector <double>(nums.size() + 1, -1.00) );
        // visitedStates.resize((int)nums.size()+1, vector<double > ((int)nums.size()+1,-1.00));
        // cout<<visitedStates.size() <<" "<<visitedStates[0].size()<<endl;
        return solve(nums,k,0,visitedStates);
         
    }
    
};