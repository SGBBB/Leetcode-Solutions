/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,h=n ,ans=INT_MIN;
        for(;l<=h;){
            int mid=l+( (h-l)>>2 );
            int res=guess(mid);
            cout<< "mid is "<<mid<< endl;
            if(!res)  return ans=mid;
            (res==-1)?h=mid-1: l=mid+1 ; 
        }
        return 6;
    }
};