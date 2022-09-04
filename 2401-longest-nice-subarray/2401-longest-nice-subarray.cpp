class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bitsStore(31,0);
        int n=nums.size(),maxSubArrSize=1;
        
        //There wil be two pointers s,e
        for(int s=0,e=0;e<n;e++){
            //It tells whether bitSize >1 or not
            int bitSize=0;
            //This will take constant time
            //Here we increased bitSize at every bit and got to now whether bitsStore[j]>1 
            for(int j=0;j<31;j++){
                bitsStore[j]+=(nums[e] & 1<<j)>0;
                if(bitsStore[j]>1){
                    bitSize=1;
                }
                    
            }
            // cout<< nums[e]<<"   ";
            // for(auto it:bitsStore) cout<<it<<" ";
            // cout<<endl;
            //if bitSize is increased
            while(s<e &&  bitSize>0){
                int curBitSize=0;
                //chop out your nums[s] from bitsStore
                for(int j=0;j<31;j++){
                    bitsStore[j]-=(nums[s] & 1<<j)>0;
                    if(bitsStore[j]>1){
                        curBitSize=1;
                    }
                    
                }
                
                
                bitSize=curBitSize;
                
                s++;
                
                
            }
            
            
            maxSubArrSize=max({maxSubArrSize,e-s+1});
            
            
            
            
        }
        
        // cout<<"fuck "<<endl;
        // cout<<((  nums[1] & (  1<<1)  )>0)<<endl;
        return maxSubArrSize;
    }
};
/*
10 4 3 8 48  10


32  16  08  04  02 01 
0   0    1   1   2  1

0   0    0   1   1  1

0   0    1   0   1  0 


any no. will not go above 2^30


*/