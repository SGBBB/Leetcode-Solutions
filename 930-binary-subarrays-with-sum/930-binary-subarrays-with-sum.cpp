class Solution {
    int atmost(vector<int>& nums, int k){
        if(k<0) return 0;
        int i=0,j=0,cnt=0,sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            if(sum<=k)
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=atmost(nums,goal)-atmost(nums,goal-1);
        cout<<atmost(nums,goal)<<" "<<atmost(nums,goal-1)<<endl;
        return ans;
        
    }
};