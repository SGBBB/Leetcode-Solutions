class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        vector<int> arr[101];
        for(auto it:rectangles){
            arr[it[1]] .push_back(it[0]);
        }
        
        for(auto &it:arr) {
            sort(it.begin(),it.end());
        }
        vector<int> ans;
        
        for(auto it:points){
            int cnt=0;
            for(int i=it[1];i<=100;i++){
                //applying lower bound on width
                int idx=lower_bound(arr[i].begin(),arr[i].end(),it[0] )-arr[i].begin();
                cnt+=arr[i].size()-idx;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    /*
     time complexity-> points.size() * 100   
        */
};
/*
Agenda : I just have to cnt how many rectangles are over;apped over points c
coordinates.
How can i move ahead solving this problem?????

*/