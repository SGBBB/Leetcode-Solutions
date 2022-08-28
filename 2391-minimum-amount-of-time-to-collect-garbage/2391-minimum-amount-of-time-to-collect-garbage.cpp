class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        /*
        
        P
            G
            M
            
            
            
            Does the sequence of picking up different type of garbage                       matters?????
            0 M
            1 P
            2 G
        */
        int PMaxIdx=-1,MMaxIdx=-1,GMaxIdx=-1,PMinTime=0,MMinTime=0,GMinTme=0;
        int n=garbage.size();
    
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].size();j++){
                 
                if(garbage[i][j]=='M')
                    MMaxIdx=i,MMinTime++;
                else if(garbage[i][j]=='P')
                    PMaxIdx=i,PMinTime++;
                else 
                    GMaxIdx=i,GMinTme++;
                 
            }
        }
        
        //making prefix sum of travel
        int prefixSum=0;
        for(auto &it:travel){
            it+=prefixSum;
            prefixSum=it;
        }
        // Checking if any van moved more than 0 th idx or not
        if(PMaxIdx>0){
            PMinTime+=travel[PMaxIdx-1];
        }
        if(MMaxIdx>0){
            MMinTime+=travel[MMaxIdx-1];
        }
        if(GMaxIdx>0){
            GMinTme+=travel[GMaxIdx-1];
        }
        
        return PMinTime+MMinTime+GMinTme;
    }
};