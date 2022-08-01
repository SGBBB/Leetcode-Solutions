class Solution {
public:
    vector<int> platesBetweenCandles (string s, vector<vector<int>>& queries) {
        vector<int> A,plates_cnt, res;
        
        for (int i = 0,cnt=0; i < s.size(); ++i)
            if (s[i] == '|'){
                A.push_back(i),plates_cnt.push_back(cnt);
                 
            }
                
            else
                cnt++;
        for (int q = 0; q < queries.size(); ++q) {
            int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
            int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
            // cout<<i <<" " <<j <<endl;
            // res.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);
            // cout<< s[A[j]] <<endl;
            res.push_back(!(i<j)?0:plates_cnt[j]  - plates_cnt[i]);
        }
        return res;
    }
    vector<int> platesBetweenCandles1(string s, vector<vector<int>>& queries) {
        vector<int> plate_pos,plate_cnt;
        int cnt=0;
        for(int i=0,sz=s.size();i<sz;i++){
            if(s[i]=='|'){
                plate_pos.push_back(i),
                s[i]='0'+cnt;
                
            }
            else
                cnt++;
        }
        vector<int> res;
        // time complexity=no of queries*log(len(s))
        for(auto it:queries){
            int leftPos= lower_bound(plate_pos.begin(),plate_pos.end(),it[0])-plate_pos.begin(),
                rightPos=upper_bound(plate_pos.begin(),plate_pos.end(),it[1])-plate_pos.begin()-1;
           
            cout<< leftPos<<" "<<rightPos <<endl;
            res.push_back(leftPos<rightPos?
                          s[plate_pos[rightPos]]-'0'-s[plate_pos[leftPos]]-'0':0);
            
        }
        
        return res;
    }
};
/*

**|**|***|
  |**|
     |***|
     
122344567 7
123456789 10
002005000 7

*/