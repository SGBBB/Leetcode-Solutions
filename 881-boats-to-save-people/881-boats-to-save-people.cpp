class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /*
        1. sort the people array
        2. which ever is the big guy among guy at i or j ,
        knd of try to agtrgate until you are still less than limit 
        3. try to shrink the space until you i and j intersect each         other. 
        
        NOTE:At once i can accomodate atmpst 2 guys in a boat
        
        
        */
        // sort(people.begin(),   people.end());
        // int i,j,n,cnt=0;
        //  n=people.size();
        // for(i=0,j=n-1;i<=j;i++){
        //     if(  people[i]+people[j]<=limit) j--; 
        //     cnt++;
        // }
        // return i;
        int i, j;
        sort(people.rbegin(), people.rend());
        for (i = 0, j = people.size() - 1; i <= j; ++i)
            if (people[i] + people[j] <= limit) j--;
        return i;
        /*
        1 2. 2 3
        */
    }
};