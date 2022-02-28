class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (!nums.size()) return {};
        nums.push_back(-8);//when my iterator will reach at this element it will just coollect the preserved odutput
        long min_no=nums.front(),prev=nums.front() ;
        
        for(int n:nums){ 
            if(n==nums.front()  or  prev+1==n){
                prev=n;
            
            }
            else {
                if(min_no!=prev) ans.push_back( string(to_string(min_no)+"->"+to_string(prev)) );
            else  ans.push_back( string(to_string(prev)  ));
                
                 min_no=n,prev=n;
            }
                                    
            }
        
        return ans;
    }
};