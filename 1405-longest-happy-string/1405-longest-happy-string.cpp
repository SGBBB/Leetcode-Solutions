class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        string s="";
        if(!max({a,b,c}) ) return s;
        // for(auto i:M){
        //     pq.push({i.second,i.first});
        // }
        if(a)
        pq.push({a,'a'});
        if(b)
            pq.push({b,'b'});
        if(c)
            pq.push({c,'c'});
        
        while(pq.size()){
            int cnt1=pq.top().first;
            char ch1=pq.top().second;
            pq.pop();
            s+=string(min(2,cnt1),ch1);
            cout<<"up "<<s<<endl;
            if(cnt1-min(2,cnt1)>0) {
                if(!pq.size()) return s;
                else{
                    int cnt2=pq.top().first;
                    char ch2=pq.top().second;
                    pq.pop();
                    int used_cnt2=( cnt2>(cnt1/2) )?min(2,cnt2):min(1,cnt2) ;
                    s+=string(used_cnt2,ch2),cnt2-=used_cnt2;
                    cout<<pq.size()<< "down "<<s<<endl;
                    pq.push({cnt1-min(2,cnt1),ch1});
                    if(cnt2>0) pq.push({cnt2,ch2});
                } 
            }
        }
        return s;
    }
};