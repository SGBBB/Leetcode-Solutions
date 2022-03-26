```
Try for this test case
7
2
[2,2,-1,2,2,2,1]
[0,2,1,0,0,0,0]
​
​
//another test case
9
2
[2,2,-1,2,2,2,1,5,5]
[0,2,1,0,0,6,0,0,0]
```
​
*Working Code*
```
vector<vector<int>> v;
vector<int> t;
​
class Solution {
public:
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
v.clear();
v.resize(n);
t = informTime;
for (int i = 0; i < n; ++i) {
if (manager[i] != -1) {
v[manager[i]].push_back(i);
}
}
return dfs(headID);
}
int dfs(int m) {
int res = 0;
for (int i : v[m]) {
res = max(res, dfs(i));
}
return res + t[m];
}
};
```