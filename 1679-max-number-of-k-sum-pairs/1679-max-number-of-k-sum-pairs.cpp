class Solution {
public:
//     int maxOperations(vector<int>& nums, int k) {
//         int cnt=0;
//         sort(nums.begin(),nums.end());//nlogn
//         int i=0,j=nums.size()-1;
//         while(i<j){//O(n)
//             if(nums[i]+nums[j]==k)cnt++,i++,j--;
//             else if(nums[i]+nums[j]<k) i++;
//             else j--;
//         }
        
//         return cnt;
//     }
    //Tc: O(nlogn)+O(n)=O(nlogn)
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int ans = 0;
        for (int b : nums) {
            int a = k - b; // Explain: a + b = k  =>  a = k - b
            if (seen[a] > 0) {
                ans += 1;
                seen[a] -= 1;
            } else {
                seen[b] += 1;
            }
        }
        return ans;
    }
};
/*
Time & Space: O(N)
*/