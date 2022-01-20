```
map<int, unordered_set<string> > ans;
void dfs(const string &s, int cur, int leftCount, int rightCount, string path) {
if (rightCount > leftCount) return;
if (cur == s.length()) {
if (leftCount == rightCount) ans[path.length()].insert(path);
return;
}
if (s[cur] != '(' && s[cur] != ')')  path += s[cur];
dfs(s, cur+1, leftCount, rightCount, path);
if (s[cur] == '(') { dfs(s, cur+1, leftCount+1, rightCount, path+'('); }
if (s[cur] == ')') { dfs(s, cur+1, leftCount, rightCount+1, path+')'); }
}
public:
vector<string> removeInvalidParentheses(string s) {
dfs(s, 0, 0, 0, "");
cout<<"printing eleemnts inside set"<<endl;
for( auto i : ans ){
cout<<i.first<<" --- ";
for(auto j:i.second ) cout<<j<<" "<<endl;;
}
vector<string> arr= vector<string>(ans.rbegin()->second.begin(), ans.rbegin()->second.end());
// for(string word:arr) cout<<word<<" ";
return arr;
}
```