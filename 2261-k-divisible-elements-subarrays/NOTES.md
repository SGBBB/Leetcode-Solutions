```
struct Trie {
unordered_map<int, Trie*> ch;
int cnt = 0;
int insert(vector<int>& nums, int i, int k, int p) {
if (i == nums.size() || k - (nums[i] % p == 0) < 0)
return 0;
if (ch[nums[i]] == nullptr) ch[nums[i]] = new Trie();
int returnStuff=
ch[nums[i]]->insert(nums, i + 1, k - (nums[i] % p == 0), p);
//recursion is called here
ch[nums[i]]->cnt ++;
bool res=( ch[nums[i]]->cnt==1);
cout<< nums[i] <<" "<<i <<" <==> " << ch[nums[i]]->cnt <<endl;
returnStuff+=res;
return returnStuff;
}
};
class Solution {
public:
int countDistinct(vector<int>& nums, int k , int p) {
int res = 0;
Trie t;
for (int i = 0; i < nums.size(); ++i){
int temp = t.insert(nums, i, k , p) ;
cout<<"temp is "<<temp<<endl<<endl;
res +=temp;
}
return res;
}
/*
Complexity of this solution is n^2 becoz for i=0->(n-1)
we can create new trie as well
*/
};
​
```