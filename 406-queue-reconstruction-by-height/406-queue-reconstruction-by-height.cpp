bool cmp(vector<int> p1, vector<int> p2){            
            if(p1[0]==p2[0]) return p1[1]<p2[1];
            return p1[0]>p2[0];
        }

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), cmp);
        for(auto i:people){
            cout<< i[0]<<" "<<i[1]<<endl;
        }
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++){
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;
        // 
    }
    // static bool cmp(vector<int>& p1, vector<int>& p2){
    //     if(p1[0]!=p2[0]) return p1[0]>p2[0];
    //     else return p1[1]<p2[1];
    // }
};