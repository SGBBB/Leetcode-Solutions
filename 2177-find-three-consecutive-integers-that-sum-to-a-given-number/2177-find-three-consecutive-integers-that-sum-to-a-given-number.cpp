class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // ;
        if(num%3) return {};
//         
         long long mid_guy=num/3;
         return  vector<long long> {(mid_guy-1) ,mid_guy, mid_guy+1} ;
    }
};