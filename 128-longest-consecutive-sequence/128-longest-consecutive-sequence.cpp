class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        unordered_map<int,int > M;
        for(auto i:nums)
            M[i]++;
        int ans=0;
        for(auto i:nums){
            if(!M.count(i-1) ){
                int size=1;
                int curr=i+1;
                while(M.find(curr)!=M.end() ){
                    curr++;
                    size++;
                }
                ans=max(ans,size);
            }
                
        }
        return ans;
    }
    int longestConsecutive(vector<int>& nums) {
        /*
        
        100,4,200,1,3,2
         
        0,3,7,2,5,8,4,6,0,1
        0 1 2 3 4 5 6 7 8
        
        
        */
        int len=nums.size();
        unordered_map<int,int > nums_store;
        for(int it:nums)
            nums_store[it]++;
        int longest_len=0;
        for(auto it:nums_store){
            if(!nums_store.count(it.first-1)){
                int cur_len =1,
                next_val=it.first+1;
                while( nums_store.find(next_val)!=nums_store.end() ){
                    cur_len++,
                    next_val++;
                
                
                }
                longest_len=max({longest_len,cur_len});
            }
            
        }
        return longest_len ;
    }
};