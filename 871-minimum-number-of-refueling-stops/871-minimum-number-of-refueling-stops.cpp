class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        /*
        0           10
        start      I station
        
        
        100
        160
        */
        multiset<int> S;
        int farthest_we_can_reach=startFuel,n=stations.size(),i=0,cnt=0;
        while(farthest_we_can_reach<target){
            while(i<n && stations[i][0]<=farthest_we_can_reach){
                S.insert(stations[i][1]);
                i++;
            }
            //If set is empty and we are unable to reach target then return -1;
            if(S.empty())
                return -1;
            int highestFuelValue=*(--S.end());
            farthest_we_can_reach+=highestFuelValue;
            S.erase(--S.end());
            cnt++;
        }
        return cnt;
    }
};