class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev=0,next=0,curr=0,len=flowerbed.size();
        for(int i=0 ; i<len and n; i++){
            curr=flowerbed[i] ;
            prev=(!i) ? 0 : flowerbed[i-1] ;
            next=(i==len-1) ?  0 : flowerbed[i+1]  ;
            if( !max({prev,next,curr }) ) flowerbed[i]=1,n--;
        }
        return n<=0;
    }
};