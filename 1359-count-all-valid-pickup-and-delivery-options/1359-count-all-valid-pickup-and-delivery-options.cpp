class Solution {
public:
    int countOrders(int n) {
        long mod=1000000007,res=1;
        for(int i=1;i<n+1;i++){
            res*=i,res%=mod;
            res*=(2*i-1), res%=mod;
            
        }
        return res%mod;
    }
};