class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(!poured) return 0.000000;
        //Now my poured is no more 0
        double capacity[103][103]={0.0};
        capacity[0][0]=poured;
        
        for(int i=0;i<101;i++){
            // if(!i[0]) continue;//ignoring the oth guy but why???
            for(int j=0;j<i+1;j++){
                //
                if(capacity[i][j]>=1){
                    
                    double extra = capacity[i][j]-1;
                    capacity[i][j]= 1;
                    if(!extra) continue;
                    extra/=(2.000);
                    // if(i==1) cout<<extra <<endl;
                    capacity[i+1][j]+= extra, capacity[i+1][j+1]+=extra;
                }
                // cout<<capacity[i][j]<<" ";
            }//cout<<endl;
        }
        // cout<<capacity[0][0]<<endl;
        cout<< "backchodi "<< !(0.0000)<<endl;
        return capacity[query_row][query_glass];
    }
};