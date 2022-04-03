class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1,h=*max_element(begin(candies), end(candies));
        int ans=0;
        while(l<=h){
            int mid=(l+h)>>1;
            /*black box stuff states im passing mid as the value of candy each guy gets return true if its possible to distribute these m candies among k chikldren????
            
            */
            long long cnt=0;//it will store number of children that can be fed by mid amount of candies
            for(int num:candies) cnt+=num/mid;
            if(cnt<k) h=mid-1;
            else {ans=mid; l=mid+1;}
            
        }
        return ans;
        
    }
};
/*
5 8 6
3

 Whats the maximum no of candy a children can get???????
 Since we cant merge 2 candies into 1 so at worst case 1 child  can get atmost  candy equivalent to maximum pile value.
 minimum candy he can get is 1.
 

*/