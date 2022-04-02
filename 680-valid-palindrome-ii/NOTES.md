```
bool flag = 0;
bool validPalindrome(string s) {
return helper(s, 0, s.size() - 1);
}
bool helper(string &s, int l, int r) {
if(l >= r)
return true;
// same
if(s[l] == s[r])
return helper(s, l+1, r-1);
// Not same for 2nd time
if(flag)
return false;
// not same for first time
flag = 1;
return helper(s, l+1, r) || helper(s, l, r-1);
}
```
​
​
​
​
```
public boolean validPalindrome(String s) {
return validSubPalindrome(s, 0, s.length() - 1, false);
}
​
private boolean validSubPalindrome(String s, int lo, int hi, boolean used) {
if (lo >= hi) { // base case
return true;
}
if (s.charAt(lo) != s.charAt(hi)) { // equal
if (used == false) {
if (validSubPalindrome(s, lo + 1, hi, true)) return true; // test left deletion
return validSubPalindrome(s, lo, hi - 1, true); // test right deletion
} else {
return false;
}
}
return validSubPalindrome(s, lo + 1, hi - 1, used);
}
```