class Solution {
public:
    int largestCombination(vector<int>& cs) {
        /*
        101
        110
        1
        
        
        16,17,71,62,12,24,14
        12 14 16 17 24 62 71 
        
        1000111                   71
         111110                    62
          11000                     24
          10001                     17
          10000                     16
           1110                      14
           1100                      12
        */
        int res = 0, max_e = *max_element(begin(cs), end(cs));
        // starting from 1 since 2^0 is 1
        for(int i=1;i<=max_e;i=i*2){
            int cnt=0;
            for(int num:cs)
                cnt+=(num & i)>0;
            res=max(res,cnt);
        }
        
        // cout<< (12 & 8 ) <<endl;
        return res;
        
    }
};