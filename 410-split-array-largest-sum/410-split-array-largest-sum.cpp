class Solution {
    int f(vector<int>& v, int m,int M){
        int cnt=1,sum=0;
        for(int x:v){
            if(sum+x>M) {sum=x;cnt++;}
            else sum+=x;
            
        }
        return cnt<=m;
    } 
public:
    int splitArray(vector<int>& nums, int m) {
        /*
        Generally in these variety of problems ans lies in search space if we have thought about search space most of the work is done by our side.
        intuition --->we are building is we are building subarrays with certain values decided while using binary search technique
        every time we are checkcing whether m length subarrays are possible if we consider subarrays having sum as mid value we are passing.
        
        */
        int l=*max_element(nums.begin(),nums.end())  ,  h=accumulate(nums.begin(),nums.end(),0),ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            cout<<"mid is "<<l<<mid<< h<<endl;
            if(f(nums,m,mid)){ // subarray count is less than equals to given m
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
        
    }
};