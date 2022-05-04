class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char ,int > frequency ;
        int c=0;
        for(char ch:s) {c+=(ch=='u');frequency[ch]++;}
        cout<<"u are "<<c<<endl;
        cout<<"sz is "<<s.size()<<endl;
        priority_queue<  pair<char ,int > > pq;
        string ans="";
        for(auto [ch,cnt]:frequency)  {cout<<ch << " "<<cnt <<endl;pq.push( {ch, cnt} );}
        // for(;pq.size();pq.pop()) cout<<pq.top().first<<endl;
        for( ;!pq.empty(); ){
            char ch1=pq.top().first;
            int cnt1=pq.top().second;
            pq.pop();
            int len=min(repeatLimit, cnt1 ),remaining=cnt1-len;
            
            ans+=string(min(repeatLimit, cnt1 ) , ch1 );
            if(cnt1-repeatLimit>0){//if unchi aukat vala bnda ki freq rehti hai then  then  vo is body m ayega
                char ch2;
                int cnt2;
                if(pq.size()){
                    ch2=pq.top().first;
                    cnt2=pq.top().second;
                    pq.pop();
                    ans+=string(1,ch2);
                    if(cnt2-1>0) pq.push({ch2,cnt2-1});
                }
                else return ans;
                pq.push({ch1,cnt1-repeatLimit});
                
            }
            
        }
        return ans;
    }
};