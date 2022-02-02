class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> time(n);
        
        
        for(int i=0;i<n;i++) {time[i]=((dist[i]-1)/speed[i]);
                              cout<<time[i]<<endl;}
        sort(time.begin(),time.end());
        int current_time=0,cnt=0;
        for( ;   current_time<n and time[current_time]>=current_time;current_time++){
            cnt++;
        }
        return cnt;
    }
};