class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        /*
        3,3,3,3,5,5,5,2,2,7
        5 5 5 2 2
        
        3 -4
        5 -3
        2 -2
        7 -1
        
        3 3 3 3 4 4 5 5
        
        3 4
        4 2 
        5 2
        
        
        
        */
        map<int,int> M;
        for(auto it:arr)
            M[it]++;
        vector<int> freq;
        for(auto it:M){
            freq.insert(freq.end(),it.second);
        }
        //Sort it in reverse order
        sort(freq.rbegin(),freq.rend());
        int barrier=n/2,cnt=0;
        for(auto it:freq){
            //updating cnt every time
            cnt++;
            barrier-=it;
            if(barrier<=0){
                return cnt;
            }
            
        }
        
        
        
        
        return cnt;
    }
};