class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long min_time=INT_MAX;
        for(int t:time)  min_time=min(min_time,t*1LL);
        long long l=1,h=1LL*min_time*totalTrips, ans;
        
        for( ;l<=h; ){ 
            long long mid=l+(h-l)/2 ,
            sum=0;
            //black box vala kam 
            for(int t:time)  sum+=(  (mid)/t  );
            //sum is holding the no of tripps all cars can make in total
            //if sum is >= totalTrips then hold the mid value because it can be the potential ans let you shrink the search space to left.
            if(sum>=totalTrips) {
                h=mid-1;
                ans=mid;
            }
            else l=mid+1;//if sum is less than total trips then obviously i must increase the total time 
            // cout<<sum<<" "<<mid<<" "<<h<<endl;
        }
        return l;
    }
};