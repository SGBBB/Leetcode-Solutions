class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int ,long long > cntMap,sumMap;
        int i,n=arr.size();
        vector<long long> ans(n);
        
        for( i=0;i<n;i++){
            ans[i]+=(cntMap[arr[i]]*i ) - sumMap[arr[i]] ,
            cntMap[arr[i]]++,  sumMap[arr[i]]+=i  ;
            
        }
        cntMap.clear(),sumMap.clear();
        for(i=n-1;i>-1;i--){
            ans[i]+= sumMap[arr[i]]-(cntMap[arr[i]]*i)  ,
            cntMap[arr[i]]++,  sumMap[arr[i]]+=i  ;
        }
        return ans;
        
    }
};