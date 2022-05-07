```
int n = nums.size();
int *prefix = new int[n]();
prefix[0] = nums[0];
for(int i = 1 ;i<n ; i++){
prefix[i] = min(prefix[i - 1] , nums[i]);
}
set<int> s;
s.insert(nums[n - 1]);
for(int i = n - 2 ; i >=0  ; i--){
auto it = s.lower_bound(nums[i]);
if(it!= s.begin()){
it--;
if(*it > prefix[i]){
return true;
}
}
s.insert(nums[i]);
}
return false;
```