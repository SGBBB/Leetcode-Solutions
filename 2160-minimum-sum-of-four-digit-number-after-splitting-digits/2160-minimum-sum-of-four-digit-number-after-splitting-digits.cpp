class Solution {
public:
    int minimumSum(int num) {
        string str=to_string(num);
        sort(str.begin(),str.end());
        int ans=((str[0]-'0')*10 ) + (str[2]-'0') +
            ((str[1]-'0')*10 ) + (str[3]-'0');
        return ans;
    }
};

// 2239