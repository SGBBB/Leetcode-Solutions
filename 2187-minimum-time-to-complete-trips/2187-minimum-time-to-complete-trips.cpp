class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l=1,h=1e14+1, ans;
        for( ;l<h; ){ 
            long long mid=l+(h-l)/2 ,sum=0;
            //black box vala kam 
            for(int t:time)  sum+=(  (mid)/t  );
            //sum is holding the no of tripps all cars can make in total
            if(sum>=totalTrips) {
                h=mid;
                ans=mid;
            }
            else l=mid+1;
            // cout<<sum<<" "<<mid<<" "<<h<<endl;
        }
        return ans;
    }
};