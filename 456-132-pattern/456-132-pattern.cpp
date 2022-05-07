class Solution {
public:
    /*
    
    [-1 ,-2 ,-3 ,1 ,0,-3,-2,-1]
    
    */
//     bool find132pattern(vector<int>& nums) {
//         //if size of nums <3 then there will not be any pattern
//         if(nums.size()<3) return false;
        
//         return false;
//     }
    /*
    
    [-1 ,-2 ,-3 ,1 ,0,-3,-2,-1,10]
    -> we are maintaining a monotonicaly increasing stack
    -> if we met a guy greater than stack's top guy  then remove all bigger        guys than it.
    -> now s2 is holding the bigger guy among all the popped guy's
    from next iteraiton, now check whether  cur guy is smaller than s2 if yes retuunr true;
    */
    bool find132pattern(vector<int>& nums) {
        /*
        s1, s2,s3
        here we are just maintaining our s3
        */
        int s3 = INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            cout<<s3<<endl;
            if(nums[i]<s3)
                return true;
            while(!st.empty() && nums[i]>st.top())
                s3=st.top(),st.pop();
            st.push(nums[i]);
        }
        return false;
    }
};
/*

Im. unable to get what this problem is trying to. ask let alone solving it!
What language is he using 
A[i](first guy)<A[k](third guy)<A[j] (second guy)
Now i got the problem
How will i move ahead in this problem?????
This is a sequence at an index type of problem.
How will I identify the sequence?
[1 2 3 4]


[-1 3 2 0]

[-1 ,-2 ,-3 ,1 ,0,-3,-2,-1]
-3 ,0
ok i got some intuition we need to identify the pivot/middle guy.
Hint : is to use stack data structure
fact: pivot/middle can be any element except first and last guy.

I think i should use set data structure instead
Consider taking two set data structure


Try to contradict your algorithm

*/