class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> res,temp(n+1);
        for(int i=0;i<n;i++){
            int pos=groupSizes[i];
            
            //until now temp[pos].size()<pos
             
            temp[pos].push_back(i);
            
            // if some row is filled then push that row into res
            if(temp[pos].size()==pos){ 
                res.push_back(temp[pos]);
                 
                temp[pos]= {};
                cout<<i<<" "<<temp[pos].size()<<endl;
            }
                
            
        }
        return res;
    }
};