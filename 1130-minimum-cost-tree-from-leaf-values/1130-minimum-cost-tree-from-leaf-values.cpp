map< pair<int,int>, pair<int,int> >M ;
class Solution {
    
    pair<int,int> min_cost(int i,int j,vector<int> &arr){
        cout<<" i and j  is "<<i<<" "<<j<<endl;
        
        if(i==j) return {arr[i],0};
        if(M.count({i,j})) return M[{i,j}];
        int max_idx=-1,
            min_sum=INT_MAX,n=arr.size();
        // if(i<j){
            // Now im at non leaf node
            
        for(int k=i;k<j;k++){
        cout<<"kitnin br aya "<<k<<endl;
    auto left= min_cost(i,k,arr);
    auto right=min_cost(k+1,j,arr);
       max_idx=max(left.first,right.first);
       min_sum= min(min_sum ,
left.second+right.second+ (left.first*right.first)
                   );        
              
        }
        return M[{i,j}]={max_idx,min_sum};
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        /*
        i think this is partition dp
        i to k 
        k+1 to j
        */
        M.clear();
        int n=arr.size();
        auto response= min_cost(0,n-1,arr);
        return response.second;
    }
};