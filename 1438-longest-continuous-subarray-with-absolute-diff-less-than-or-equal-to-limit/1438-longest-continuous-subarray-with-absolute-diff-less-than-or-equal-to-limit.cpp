class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int n=nums.size(),i=0,j =0,maxLen=1;
        // long mini=INT_MAX,maxi=INT_MIN;
        // queue<int> q;
        // multiset<int> cnt;
        // while(j<n){
        //     q.push(nums[j ]),
        //     cnt.insert( nums[j] );
        //     while( abs(*--cnt.end()-*cnt.begin() )>limit ){
        //         cnt.erase(cnt.find(nums[i])),
        //         i++;
        //     }
        //     maxLen=max(maxLen,j-i+1),
        //     j++;
        // }
        // return maxLen;
        // //time complexity is NlogN
//         deque<int> mini,maxi;
        
//         while(j<n){
//             while(!mini.empty() && mini.back()>nums[j] )  mini.pop_back();
//             while(!maxi.empty() && maxi.back()<nums[j] )  maxi.pop_back();
//             maxi.push_back(nums[j]),
//             mini.push_back(nums[j]);
            
//             if(maxi.front() -mini.front() >limit){
//                 if(maxi.front()==nums[i]) maxi.pop_front();
//                 if(mini.front()==nums[i]) mini.pop_front();
//                  i++;
//             }
//             if(j-i+1>maxLen) 
//                 maxLen=j-i+1;
            
            
            
//             j++;
                
//         }
        vector<int> A=nums;
        deque<int> maxd, mind;
        int i = 0, j,maxLen=1;
        for (j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            if(maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
            maxLen=max(maxLen,j-i+1);
        }
        
        cout<<j<<" "<<i<<endl;
        return j - i;
        // return maxLen;
        //Time Complexity is linear
    }
};

/*

How will I solve this problem?
I need to minimise difference btw largest and smallest element in every sub-array
If I found the difference btw largest and smallest guy > limit , so i have to eat elements from left side 
8 2 4 7     limit = 4
10 1 2 4 7 2   limit = 5
4 2 2 2 4 4 2 2     limit = 0


4 2 2 2 4 4 2 2 limit(8)
            i 
maxd=     2  2
mind=     2 2

*/