class Solution {
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]>b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0,tc=truckSize;
        for(auto i:boxTypes){
        
            if(tc<=i[0]) {ans+=( tc *i[1]); return ans;}
            else 
                {
                    ans+=(i[0]*i[1]);
                    tc-=i[0];
                }       
        
        cout<<tc<<" "<<ans<<endl;
    }
        return ans;
    }
};

/*
88
27

*/