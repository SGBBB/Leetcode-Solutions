class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // holder which will contain all possible remainders
        int arr[60]={},ans=0;
        for(int i:time){
            int b=i%60;
            int a=!b ?0 : 60-b;
            ans+=arr[a];
            arr[b]++;
        }
        return ans;
    }
};