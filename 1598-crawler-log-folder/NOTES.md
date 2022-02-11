```
# int minOperations(vector<string>& logs) {
int p=0;
for(auto &x: logs) {
if(x=="../" ) {
if(p>0)
--p;
continue;
}
if(x!="./")
++p;
}
return p;
}
```