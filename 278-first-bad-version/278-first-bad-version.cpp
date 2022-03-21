// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        long l=1,h=n,mid=0,ans=INT_MAX-1;
        while(l<=h){
            mid=l+(h-l)/2;
            //if you found a bad version then shrink serach space towards left
            if(isBadVersion(mid)){ 
                ans=mid;
                h=mid-1 ;
            }            
            else l=mid+1;
        }
        return ans;
    }
};

/*
1 2 3 4 5 
*/