class Solution {
    int f(vector<int>& v, int m,int M){
        int cnt=1,sum=0;
        for(int x:v){
            // if(x>M) return 0;
            if(sum+x>M) {sum=x;cnt++;}
            else sum+=x;
            
        }
        return cnt<=m;
    } 
public:
    int splitArray(vector<int>& nums, int m) {
        int l=*max_element(nums.begin(),nums.end())  ,  h=accumulate(nums.begin(),nums.end(),0),ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(f(nums,m,mid)){ // subarray count is less than equals to given m
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
        
    }
};