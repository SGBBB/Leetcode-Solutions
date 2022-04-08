else
end = true;
}
bool find(string &s, int p = 0, bool wild = false) {
if (p == s.size())
return wild && end;
int idx = s[p] - 'a';
return (ch[idx] != nullptr ? ch[idx]->find(s, p + 1, wild) : false) || (wild ? false : find(s, p + 1, true));
}
};
class Solution {
public:
int wordCount(vector<string>& startWords, vector<string>& targetWords) {
Trie t;
for (auto &w : startWords) {
sort(begin(w), end(w));
t.insert(w);
}
int res = 0;
for (auto &w : targetWords) {
sort(begin(w), end(w));
cout<< w<<" "<<t.find(w) <<endl;
res += t.find(w);
}
return res;
}
```