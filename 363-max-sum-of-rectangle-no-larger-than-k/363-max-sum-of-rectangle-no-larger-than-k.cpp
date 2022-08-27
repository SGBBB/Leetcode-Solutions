class Solution {
    int f(vector<int> &arr,int target ){
        
        set<int> s;
        int maxArea=INT_MIN;
        s.insert(0);
        int n=arr.size(),prefixSum=0;
        
        
            
            
         
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
             
            // lower bound returns if current element ni mila then ussse bda return krdega
            set<int>::iterator it=s.lower_bound(prefixSum-target);
            if(it!=s.end()){
                 
                maxArea=max({maxArea,prefixSum-*it});
            }
            s.insert(prefixSum);
        }
         
        return maxArea;
    }
    int find_max(vector<int>& arr, int k)
    {
        int n = arr.size();
        
        int maxi = INT_MIN;
        
        // curr_sum will store cumulative sum
        
        int curr_sum = 0;
        
        // set will store the prefix sum of array
        
        set<int> s;
        
        // put 0 into set, if curr_sum == k, (curr_sum - k) will be zero 
        
        s.insert(0);
        
        for(int i = 0; i < n; i++)
        {
            // calculate cumulative sum
            
            curr_sum += arr[i];
            
            // find the prefix sum in set having sum == curr_sum - k
            
            auto it = s.lower_bound(curr_sum - k);
            
            // if prefix sum is present, update the maxi
            
            if(it != s.end())
            {
                maxi = max(maxi, curr_sum - *it);
            }
            
            // insert prefix sum into set
            
            s.insert(curr_sum);
        }
        
        return maxi;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
         
        // int r=matrix.size(),c=matrix[0].size(),ans=INT_MIN,chk1=0;
        // //iterating through each row
        // for(int i=0;i<r;i++){
        //     vector<int>a(c,0);
        //     //iterating through start of current row until the remaining rows
        //     for(int j=j;j<r;j++){
        //         //travel through each column 
        //         for(int k=0;k<c;k++)a[i]+=v[j][k];
        //         int maxArea=find_max( a,target );
        //         ans=max(ans,maxArea);
        //     }
        // }
        // return ans ;
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        int maxi = INT_MIN;
        
        // fix the position of two rows and take cumulative sum of columns between two fixed rows
        
        for(int start_row = 0; start_row < n; start_row++)
        {
            vector<int> col_array(m, 0);
            
            for(int end_row = start_row; end_row < n; end_row++)
            {
                // take cumulative sum of columns between two fixed rows
                
                for(int col = 0; col < m; col++)
                {
                    col_array[col] += matrix[end_row][col];
                }
                
                // find maximum subarray having sum less than equal to k
                
                int curr_max = find_max(col_array, target);
                
                // update the maximum sum
                
                maxi = max(maxi, curr_max);
            }
        }
        
        return maxi;
        
    }
    
    
    /*
    
    1 -2 4
    
    
    */
};