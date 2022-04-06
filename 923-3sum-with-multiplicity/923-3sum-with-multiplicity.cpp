class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
//         int n=arr.size();
//         for(int i=0;i<n-2;i++){
// //             for(int j=i+1,k=n-1;ij<k;){
                
// //             }
//         }
//         return 12;
        unordered_map<int, int> m;
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            res = (res + m[ target - arr[i] ] ) % mod;//if target - arr[i] is in map, it means we have a three-sum, so we add it to the result.
            for (int j = 0; j < i; j++) {
                m[ arr[i] + arr[j] ]++;
            }
        }
        return res;
    }
};
/*

1, 1,2,2,2,2


1 2 2 



another case:
1,1,2,2,3,3,4,4,5,5

1 2 5 
2 3 3
2 2 4
1 3 4

Observations:
How should i make progress in the problem?
One thing is fine i is gonna iterate over every i leading to O(n2) time complexity as internally also we are doing some linear time complexity work.
What if  i sort the array?


*/