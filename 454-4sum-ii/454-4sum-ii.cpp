class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int i=0,j=0,k=0,l=0,n=nums1.size(),cnt=0;
        unordered_map<int,int> M1;
        for(int i:nums1)
            for(int j:nums2){
                //logic
                M1[i+j]++;     
            }
        for(int i:nums3)
            for(int j:nums4){
                //logic
                cnt+=M1[(-1)*(i+j)];     
            }
        return cnt;
                
    }
};