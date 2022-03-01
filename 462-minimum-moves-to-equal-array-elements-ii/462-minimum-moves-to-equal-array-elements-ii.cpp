class Solution {
public:
    int minMoves2(vector<int>& nums ) {
        long long idx=0, last_guy=0, prev=0, sum=0, next=0, min_move=LLONG_MAX;
        int n=nums.size();
        for(int i:nums) sum+=i;
        sort(nums.begin(),nums.end());
        for(int i:nums){
            prev+=( idx*(i-last_guy)*1LL   );
            next=sum- ( (n-idx)*i*1LL);
            cout<<prev+next<<endl;
            min_move=min(min_move,prev+next) , sum-=i ,idx++ ,last_guy=i;
        }
    
        return min_move;
    }
};