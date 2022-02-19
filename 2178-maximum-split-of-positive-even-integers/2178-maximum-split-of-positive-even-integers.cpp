class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        
        long long val=0,i=2;
        bool flag=0;
        if(finalSum & 1) return {};
        for(;val<finalSum;i+=2){
            long long diff=finalSum-val;
            if(diff < i) {flag=!flag; break;}
            val+=i;
            ans.push_back(i);
        }
        if(flag){
            cout<<"y"<<endl;
            long long remaining=finalSum-val;
            ans.back()+=remaining;
            
        }
         
        return  ans; 
    }
};