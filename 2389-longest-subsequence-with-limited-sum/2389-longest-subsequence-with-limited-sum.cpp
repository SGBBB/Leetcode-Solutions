class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int>  answer ;
        /*
        
        2 3 5 2 1
        
        */
        // is it harm to sort the given array
        sort(nums.begin(),nums.end());
        
        //solve each query independently
        for(auto &it:queries){
            int maxLen=0;
            // iterate oveer the sorted array
            int i=0;
            while(i<n){
                // if current query went negative then break from that moment
                if(it-nums[i]<0)
                    break;
                it-=nums[i];
                maxLen++,i++;
            }
            answer.push_back(maxLen);
        }
        return answer;
    }
};