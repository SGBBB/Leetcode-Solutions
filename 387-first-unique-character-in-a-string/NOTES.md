```
class Solution {
public int firstUniqChar(String s) {
if(s==null || s.length()==0) return -1;
int slow=0,fast=0;
char[] chs=s.toCharArray();
int[] count=new int[256];
int n=chs.length;
while (fast<n){
count[chs[fast]]++;
while (slow<n && count[chs[slow]]>1){
slow++;
}
if (slow==n) return -1;
fast++;
}
return slow;
}
}
```