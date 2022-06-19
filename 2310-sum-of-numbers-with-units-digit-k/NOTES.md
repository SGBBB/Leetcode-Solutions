```
int minimumNumbers(int num, int k) {
if(num == 0) return 0;
for(int i=1; i<=10; i++){
if(ik > num) break;
if((ik) % 10 == num % 10) return i;
}
return -1;
}
​
​
​
​
```
​
​
​
testcase
8
9
ans-> -1