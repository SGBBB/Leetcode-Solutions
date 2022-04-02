class Solution {
    public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size() - 1);
    }

    bool helper(string &s, int l, int r,bool can_del = 1) {
        if(l >= r)
            return true;

        // same
        if(s[l] == s[r])
            return helper(s, l+1, r-1,can_del);
        // Not same for 2nd time
        if(!can_del)
            return false;
        // not same for first time
       
        return helper(s, l+1, r,0) || helper(s, l, r-1,0);
    }
};