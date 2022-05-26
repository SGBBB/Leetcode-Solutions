class Solution {
public:
    /*
    
    
    How will i make progress in this problem????????
    
    
    23 2 4 6 7
    
    23 25 29 1
    
     
    
    
       23 2 4 6 7
num%k   2 4 1 0
   At idx 2 sum is 29 so we did 29%6 = 5 since 5 was alredy present in hashmap so we checked the len of subarray
 
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> M; //{remainder,idx}
        int cnt=0,idx=0,sum=0;
        M[0]=-1;
        for(int i:nums){
            sum+=i;
            
            //Im doing (sum-k) becoz until cur sum, We must have encountered some k sums subarrays in my arr
            if( M.count(sum%k) ){
                if( (sum%k) && idx-M[sum%k]>=2 )
                    return true;
                /*
                  now sum%k is 0
                  fact:if sum%k is 0 then i must check the len of subarray somehow
                */
                if(idx-M[sum%k] >=2)
                    return true;
                cout<< "sum%k is "<<sum%k <<" "<<M[sum%k]<<" "<<idx  <<endl;
            }
            
            else //if some thing is not already found then insert new index
                M[sum%k]=idx;
            idx++;
        }
        return false;
    }
};