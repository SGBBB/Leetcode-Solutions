class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(string str:logs){
            if(str=="../"){
                if(cnt) cnt--;
                continue;
            }
            //if you have met some other directory except current dir then increase then cnt
            if(str!="./") cnt++;
        }
        return cnt;
    }
};