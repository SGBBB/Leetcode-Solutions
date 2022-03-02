class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size(),n2=t.size(),i,j;
        if(n1 >n2) return 0;
        for(i=0,j=0;i<n1 and j<n2;j++){
            if(s[i]==t[j]) i++;
        }
        cout<<i<<endl;
        return i==n1;
    }
};