class Solution {
    bool canWeMake(long long int row, long long int coinsHave){
        long long int coinsNeeded = (row * (row+1))/2; // here int*int can be greater than int
        return coinsNeeded <= coinsHave;
    }
public:
    int arrangeCoins(int n) {
        /*
        Hint is to use binary search in this problem
        But main challenge is how to use ???
        l=1, h=5
        for the black box try to generate some formula to compute how many rows are completed
        Can i use binary search in ans in this problem?
        
        
        h will be atmost half of num of coins
        */
        int l=1,h=n/2 +1 ,ans=0;
        while(l<=h){
            int mid=l +   (h-l)/2;
            //if we are able to make then will try with less coins
            if(canWeMake(mid,n)){
                ans=mid,
                l=mid+1;
            }
            else
                h=mid-1;;
        }
        
        return ans;
    }
};