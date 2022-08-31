class Solution {
public:
//     int maxOperations(vector<int>& nums, int k) {
//         int cnt=0;
//         sort(nums.begin(),nums.end());//nlogn
//         int i=0,j=nums.size()-1;
//         while(i<j){//O(n)
//             if(nums[i]+nums[j]==k)cnt++,i++,j--;
//             else if(nums[i]+nums[j]<k) i++;
//             else j--;
//         }
        
//         return cnt;
//     }
    //Tc: O(nlogn)+O(n)=O(nlogn)
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int ans = 0;
        for (int b : nums) {
            int a = k - b; // Explain: a + b = k  =>  a = k - b
            if (seen[a] > 0) {
                ans += 1;
                seen[a] -= 1;
            } else {
                seen[b] += 1;
            }
        }
        return ans;
    }
};
/*
How will i go ahead solving this problem???
.Observatoiins:
->return maximum no. of operations
->if k is smaller than min num of the array then retunr 0;
[1 ,1 ,1 ,1  ,2 ,3 ,4  ,2]

k(4)

Ans->2




(Q) is maximum no of operations equivalent to total opoerations ???



1  1  1  1   2  3  4   5  2  2 3 3 6 

k(7)

1  1  1  1   2 2  2 3 3 3  4   5   6 

cnt=2

Ok its just application of 2 sum



5 ,  6,8,19,21,21,21

Should i think more?????????????????????

5 ,  6,8,8,9,12,12,12
k(11)


Time complexity of this solution is nlogn
*/