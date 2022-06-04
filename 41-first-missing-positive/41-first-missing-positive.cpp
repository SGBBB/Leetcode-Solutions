class Solution {
public:
    /*
    intutiion:
    Observationi:
    1 is the smallest positive number
    no sorting algo must be used
    size of the array is invlived here 
    I need count of negative digits,
           count of positive digits,
           count of zeroes
    */
    int firstMissingPositive(vector<int>& nums) {
//         using ll=long long;
         
//         //iterating the whole array if I met 1 then 1 cant be my ans
//         ll cntZero=0,cntNegative=0,cntPositive,
//             minGuy=LONG_MAX,maxGuy= LONG_MIN,
//             len=nums.size();
//         ll sum=0;
//         for(int i=0;i<len;i++){
//             cntZero+=(!nums[i]),
//             cntNegative+=(nums[i]<0);
//             if(nums[i]>0){
//                 minGuy=min( {minGuy,(ll)nums[i]} ),
//                 maxGuy=max( {maxGuy,(ll)nums[i]} );
//                 sum+=nums[i];
//             }
            
//         }
//         cntPositive=len-(cntZero+cntNegative);
//         //if there are no positive guys or if minGuy  >1 then return 1
//         if(!cntPositive ||  minGuy>1  )
//             return 1;
//         ll expectedSum=0;
         
        
//         for(ll positiveNumCnt=cntPositive,i=minGuy;positiveNumCnt--;i++){
//             expectedSum+=i;
//         }
//         // if expected sum != preferred sum
//         if(expectedSum!=sum){
//             return abs(expectedSum-sum);
//         }
        
        
//         return maxGuy+1;
        int n=nums.size();
        for(int i=0;i< n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;
        return n+1;
    }
};