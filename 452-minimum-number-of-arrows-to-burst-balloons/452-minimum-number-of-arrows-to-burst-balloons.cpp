bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // auto cmp=[&](vector<int> a,vector<int> b){
        //     return a[1]<b[1];
        //     // if(a[1]!=b[1]) return a[1]<b[1];
        //     // return a[0]<b[0];
        // };
        sort(points.begin() ,points.end(), cmp);
        int ans=0;
        int n=points.size();
        int prev_value=0;
        for(int j=0 ;j<n;j++){
            vector<int> i=points[j];
            // if(prev_value>= i[0] and prev_value<=i[1] ) continue;
            // else prev_value=i[1], ans++;
            if(!j or i[0]>prev_value ) prev_value=i[1], ans++;
            
            
        }
        return ans;
    }
};