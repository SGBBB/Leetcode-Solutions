class Solution {
public:
    int minTimeToType(string word) {
        
        int res = word.size(), point = 'a';
        for (auto ch : word) {
            res += min(abs(ch - point), 26 - abs( ch-point));
            point = ch;
        }
        return res;
    }
};