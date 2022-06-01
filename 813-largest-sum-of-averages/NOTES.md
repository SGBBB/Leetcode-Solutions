Start solving with this test case;
[1,2,3]
2
​
Ans->4.5
​
​
```
public double largestSumOfAverages(int[] A, int K) {
int[] sum = new int[A.length];
for (int i = 0;i < A.length; i++) sum[i] = A[i] + (i > 0 ? sum[i-1] : 0);
double[][] dp = new double[A.length][K+1];
return h(A, K, sum, dp, A.length, 0);
}
public double h(int[] A, int k, int[] sum, double[][] dp, int len, int s) {
if (dp[s][k] != 0) return dp[s][k];
if (k == 1){
dp[s][k] = ((double)(sum[len-1] - sum[s] + A[s]) / (len-s));
return dp[s][k];
}
for (int i = s; i + k <= len ; i++) {
dp[s][k] = Math.max(dp[s][k], ((double) (sum[i] - sum[s] + A[s]) / (i - s + 1)) + h(A, k-1, sum, dp, len, i+1));
}
return dp[s][k];
}
```