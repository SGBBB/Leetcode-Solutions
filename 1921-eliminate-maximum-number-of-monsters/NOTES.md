```
class Solution {
public:
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
int n=dist.size();
vector<int> time;
for(int i=0;i<n;i++) time.push_back(dist[i] / speed[i]-(dist[i] %speed[i]==0));
for(auto i:time) cout<<i<<" ,";
cout<<endl;
sort(time.begin(),time.end());
int res=0;
while(res<time.size() && res<=time[res]) res++;
return res;
}
};
```