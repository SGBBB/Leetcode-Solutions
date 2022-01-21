class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size(),total_difference=0,current_difference=0,start=0;
        for(int i=0, j=0;i<len;i++){
            int difference=gas[i]-cost[i];
            total_difference+=difference;
            current_difference+=difference;
            if( current_difference<0  ) {//if my fuel got exhausted
                start=i+1;
                current_difference=0;
            }
        }
        
        return (total_difference<0)?-1:start;
    }
};