class Solution {
    int mod=(int)(1e9) +7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>  ,greater<int>> pq(nums.begin(), nums.end());
        while(k-->0){
            int top=pq.top(); 
            pq.pop( );
            pq.push(top+1);
        }
        
        long ans=1;
        while(!pq.empty() ){
            int top=pq.top(); pq.pop();
            ans=(ans*(top))%mod;
        }
        return (int)ans;
    }
};
/*
6 3 3 4
36 6




intuition:      At last i 'll leave such digits inside my data structure such that their product will surely be maxiimum.
*/