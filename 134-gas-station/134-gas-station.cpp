class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_all =0,cost_all=0,len=gas.size();
        for(int i=0;i<len;i++) gas_all+=gas[i],cost_all+=cost[i];
        if(gas_all < cost_all)
            return -1;
        //this part will be called only if there exists an idx
        int total_value = 0;
        int start_index = 0;
        for(int i=0;i<cost.size();i++){
            total_value += gas[i]-cost[i];
            if(total_value<0){
                start_index = i+1;
                total_value = 0;
            }
        }
        
        return start_index;
        
    }
};