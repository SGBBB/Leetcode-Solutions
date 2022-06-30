class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        /*
        
        Intuiton:
        Gather all elements in a list and sort it.
        Try to bring all elements to some midway
        and check whether midway is divisible by x;
        Then I can surely bring time compelxity down
        and space complexity is also be gonna linear
        */
        int r=grid.size(), 
            c=grid[0].size();
        vector<int> arr ;
        for(vector<int> r:grid)
            for(int it:r)
                arr.push_back(it);
        sort(arr.begin(),arr.end());
        
        int midNum=arr[(r*c)/2] , cnt=0;
        
        for(int i=arr.size()-1;i>-1;i--){
            int bigGuy=(arr[i]>midNum)?arr[i]:midNum ,
                smallGuy=(arr[i]>midNum)?midNum:arr[i];
            int diff= bigGuy-smallGuy ;
            if(diff%x){
                return -1;
            }
            cnt+=(diff/x);
        }
        return cnt;
    }
};