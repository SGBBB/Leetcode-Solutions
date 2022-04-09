class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> M;
        int max_cnt=INT_MIN;
        for(int num:nums) {
            M[num]++;
            if(M[num]>max_cnt) 
                max_cnt=M[num];
        }  
        /*
        Now im done with collecting max_cnt and created fixed size 2d vector
        */
        vector<int>   bucket[ max_cnt+1];
        for(auto [val,cnt]:M){
            bucket[cnt].push_back(val);
        }
        for(int i=max_cnt;ans.size()<k;i--){
            // for(auto it:bucket[i]){
            //     if(ans.size()==k) break;
            // }
            ans.insert(ans.end(),bucket[i].begin(),bucket[i].end());
                
        }
        return ans;
    }
};
/*

Aim is to get time complexity less than nlogn
have to do this in linear time complexity.

lets take a test case where I have all unique elements 
[1,3,2,4]
now if we do bucketing then  index 1 wil be filled with all ellements .
// NOTE: it's given that  min value of k will be equal to no of unique elemtns in array
// */