class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int len=nums.size();
        k=k%len;
//         if(k==len) return;
//         for(;k-- >0   ;nums.pop_back()){
//             int temp=nums.back();
            
//             nums.insert(nums.begin()+0,temp);
//         }
        reverse(nums.begin(),nums.begin()+len-k);
        reverse(nums.begin()+len-k,nums.begin()+len);
        reverse(nums.begin(),nums.begin()+len);
    }
};