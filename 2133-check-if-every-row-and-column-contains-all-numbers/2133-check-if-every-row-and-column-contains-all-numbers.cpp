class Solution {
public:
    bool checkValid(vector<vector<int>>& v) {
        int xor1 = 0, xor2 = 0,n = v.size();
        if(n<=1) {
            return true;
        }
        for(int i=0;i<n;i++) {
            xor1=0;    xor2=0;
            for(int j=0;j<n;j++) {
				// Checking xor column wise
                xor1 = xor1^v[i][j]^(j+1);
				// Checking xor row wise
                xor2 = xor2^v[j][i]^(j+1);
            }
			// If any of them are not equal to Zero 
            if(xor1 || xor2) {
                return false;
            }
        }
        return true;
    }
};