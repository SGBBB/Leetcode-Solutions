class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        map<int,int> M;
        int n=arr.size(),sum=0;
        //inserting 0 as default value
        M.insert({0,-1});
        for(int i=0;i<n;i++){
            sum+=arr[i];
            M.insert({sum,i});
        }
        int lside=INT_MAX,res=INT_MAX;
        sum=0;//reset sum to zero
        for(int i=0;i<n;i++){
            sum+=arr[i];
            //Finding left minimum len
            if( M.count(sum-target) ){
                lside=min({ lside,i-M[sum-target]  });
            }
                
            //Findiing min len on right side as well
            if(M.count(sum+target) && lside!=INT_MAX){
                res=min({ res,lside+M[sum+target]-i});
            }
        }
        /*
        3 2 2 4  3
        3 5 7 11 14
        
        
        */
        return (res==INT_MAX)?-1:res;
    }
};