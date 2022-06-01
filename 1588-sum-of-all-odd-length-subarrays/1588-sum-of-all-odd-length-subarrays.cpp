class Solution {
    /*
    
    
    How to approach this problem??
    
    
    
    
    
    
    
    */
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        for(int i=0,sz=arr.size();i<sz;i++){
            int leftSubarrayCnt=i+1,
            rightSubarrayCnt=sz-i;
            sum+=(leftSubarrayCnt*rightSubarrayCnt+1)/2 *arr[i];//+1 is if combiniation comes out to be odd 
        }
        return sum;
    }
};