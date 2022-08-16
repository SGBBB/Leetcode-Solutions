class Solution {
public:
    int firstUniqChar(string s) {
        // 97+
        int arr[26]={};
        int i=0,n=s.size();
        queue<int> q;
//              letcode
        while(i<n){
            
            // If some char is met for the first time then only its inserted to queue
            if(!arr[s[i]-'a']){
                 
                q.push(i);
            }
            arr[s[i]-'a']++;
            //if char at front postition is repeated then remove it
            while (!q.empty() && arr[s[q.front()]-'a']>1){
                q.pop();
            }
            
            i++;
        }
        return q.empty()?-1:q.front();
    }
};