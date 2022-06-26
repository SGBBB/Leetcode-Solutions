class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int i=0,j=0,mini=0,res=INT_MAX;
        int sum=accumulate(A.begin(),A.end(),0);
        int WinSize=A.size()-k;
        while(j<WinSize){
            mini+=A[j];
            j++;
        }
        res=min(res,mini);
        while(j<A.size()){
            mini-=A[i];
            mini+=A[j];
            res=min(res,mini);
            i++;
            j++;
            // cout<<res<<endl;
        }
        
        return sum-res ;
    }
};