class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char ,int>M; 
        priority_queue< pair<int ,char> > pq; 
        for(char ch:s) M[ch ]++;
        for(auto i:M) { 
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            int cnt1=pq.top().first;
            char ch1=pq.top().second;
            cout<<cnt1<<ch1<<endl;
            
            pq.pop();
            ans+=ch1 , cnt1--;
            if( cnt1 >0 ){
                if( pq.empty() ) return "";
                else {
                    int cnt2=pq.top().first;
                    char ch2=pq.top().second;
                    cout<<cnt2<<ch2<<endl;
                    pq.pop();
                    ans+=ch2 ,cnt2--;
                    pq.push({cnt1,ch1});
                    if(cnt2>0)
                    pq.push({cnt2,ch2});
                }
            }
        }
        return ans;
    }
};