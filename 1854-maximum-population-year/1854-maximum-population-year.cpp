class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> ages(100,0);
        for(auto i:logs){
            ages[i[0]-1950 ]+=1;
            if( (i[1]-1950) <100 )ages[i[1]-1950]-=1;
            // cout<<i[0]-1950<<" " <<i[1]-1950 <<endl;
        }
        int max_pop=ages[0],year=1950;
        for(int i=1;i<100;i++){
            ages[i]+=ages[i-1] ;
            // cout<<ages[i-1]<<endl;
            if(ages[i]>max_pop)max_pop=ages[i],year=1950+i;
            
        }
        // cout<<"vals are "<<ages[10]<<ages[49]<<endl;
        return year; 
        
    }
};