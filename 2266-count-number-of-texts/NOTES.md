```
//now checking if current char ==pressedKeys[i-2] and previous guys
int limit=(ch=='7' || ch=='9' ) ?4 :3;
for(int j=i-2; j>=i-limit && j>=0  && ch==pressedKeys[j] ;j--){
dp[i]=(dp[i]+dp[j])%mod;
}
```