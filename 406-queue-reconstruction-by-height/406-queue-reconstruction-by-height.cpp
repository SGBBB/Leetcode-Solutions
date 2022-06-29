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
        /*
        After sorting the elements you will get  this
[7,0] [7,1] [6,1]  [5,0] [5,2] [4,4] 
 
 
After this you can apply insertion sort
you will get this result
[5,0] [7,0] [5,2] [6,1] [4,4]  [7,1]     
        
        */
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