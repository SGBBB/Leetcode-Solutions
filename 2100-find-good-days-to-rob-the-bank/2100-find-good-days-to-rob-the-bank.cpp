class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int l = security.size();
        vector<int> ret;
        
        vector< vector<int> > v(l,{0,0});
        for(int i = 1; i < l; i++) {
            if(security[i] <= security[i-1]) {
                v[i][0] = v[i-1][0] + 1;
            }
            if(security[l-i-1] <= security[l-i]) {
                v[l-i-1][1] = v[l-i][1] + 1;
            }
        }

        for(int i = 0; i < v.size(); i++) {
            if(v[i][0] >= time and v[i][1] >= time) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};