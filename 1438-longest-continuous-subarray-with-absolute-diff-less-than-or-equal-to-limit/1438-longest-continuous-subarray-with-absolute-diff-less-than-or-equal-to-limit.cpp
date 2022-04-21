class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size(),i=0,j =0,maxLen=1;
        // long mini=INT_MAX,maxi=INT_MIN;
        queue<int> q;
        multiset<int> cnt;
        while(j<n){
            q.push(nums[j ]),
            cnt.insert( nums[j] );
            while( abs(*--cnt.end()-*cnt.begin() )>limit ){
                cnt.erase(cnt.find(nums[i])),
                i++;
            }
            maxLen=max(maxLen,j-i+1),
            j++;
        }
        return maxLen;
        //time complexity is NlogN
    }
};

/*

How will I solve this problem?
I need to minimise difference btw largest and smallest element in every sub-array
If I found the difference btw largest and smallest guy > limit , so i have to eat elements from left side 
8 2 4 7     limit = 4
10 1 2 4 7 2   limit = 5
4 2 2 2 4 4 2 2     limit = 0

*/