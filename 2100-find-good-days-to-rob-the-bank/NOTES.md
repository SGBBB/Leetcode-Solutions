```
vector<int> goodDaysToRobBank(vector<int>& security, int time) {
int l = security.size();
vector<int> ret;
vector<pair<int, int>> v(l,{0,0});
for(int i = 1; i < l; i++) {
if(security[i] <= security[i-1]) {
v[i].first = v[i-1].first + 1;
}
if(security[l-i-1] <= security[l-i]) {
v[l-i-1].second = v[l-i].second + 1;
}
}
for(int i = 0; i < v.size(); i++) {
if(v[i].first >= time and v[i].second >= time) {
ret.push_back(i);
}
}
return ret;
}
```