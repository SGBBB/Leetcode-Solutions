class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long suffixSum =0;
        for(int num:nums) suffixSum+=num;
        long long prefixSum=0;
        int minDifference=INT_MAX,minIdx=0;
        for(int i=0,n=nums.size();i<n;i++){
            prefixSum+=nums[i],
            suffixSum-=nums[i];
            int firstAverage=prefixSum/(i+1),
                secondAverage=0;
            if(n-i-1>0)
                secondAverage=(suffixSum)/(n-i-1);
            int difference=abs(secondAverage-firstAverage);
            if(minDifference>difference)
                minDifference=difference,
                minIdx=i;
        }
        return minIdx;
    }
};
/*
Observations:
1.Actualy constraints are too strict so I cant think of solving using naive approach
2.If i divide n guys by n so ans will come in constant time complexity



*/