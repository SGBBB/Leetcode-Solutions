class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prefix=0,suffix=0,prev=0,curr=0,position,maxLen=0,k=0;
        
        int i,n=seats.size();
        // for( k=n-1;k>-1 and !seats[k] ;k--) suffix++;
        for( i=0;i<n and !seats[i] ;i++) prefix++;
        for(++i ;i<n  ;i++){
            if(seats[i]  ){
                maxLen=max(maxLen,curr);
                curr=0;
            }
            else curr++;
            suffix=curr;
        }
        int ans=max({(maxLen+1)/2 ,prefix,suffix});
        return ans  ;
        
        
    }
};