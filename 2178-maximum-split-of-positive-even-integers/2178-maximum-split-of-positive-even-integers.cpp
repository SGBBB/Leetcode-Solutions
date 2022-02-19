class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        set<long long> s;
        long long val=0,i=2;
        bool flag=0;
        if(finalSum & 1) return {};
        for(;val<finalSum;i+=2){
            long long diff=finalSum-val;
            if(diff < i) {flag=!flag; break;}
            val+=i;
            s.insert(i);
            ans.push_back(i);
        }
        if(flag){
            cout<<"y"<<endl;
            long long remaining=val+i-finalSum;//extra guy reaining
            s.erase(remaining);
            s.insert(i);
        }
        
         
        return  vector<long long>(s.begin(),s.end()); 
    }
};