class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        duration=duration-1;
        //like I have to find the difference btw independent pairs  +1; 
        int cnt=0,idx=1,prev_start=timeSeries.front(),
        prev_end=timeSeries.front()+duration
            ,len=timeSeries.size(),curr_start=0,curr_end=0;
        for(;idx<len;idx++){
            curr_start=timeSeries[idx],curr_end=timeSeries[idx]+duration;
            
            if( curr_start>prev_end ){
                cnt+=(prev_end-prev_start)+1 , prev_start=curr_start;
            }
            prev_end=curr_end;
        }
        
        
        //here I'm computing the seconds difference of lalst independent set
        cnt+=(prev_end-prev_start)+1;
        
        return cnt;
    }
};