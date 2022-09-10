bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }    
        return a[1] > b[1];
    }
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        
        int n=properties.size(),cnt=0;
        int maxDefenceVal=properties[n-1][1];
        for(int i=n-2;i>-1;i--){
            int curDefenceVal=properties[i][1];
             
            if( curDefenceVal<maxDefenceVal ){
                // update max
                
                cnt++; 
            }
            else maxDefenceVal=max({maxDefenceVal,curDefenceVal});
        }
        return cnt;
    }
};