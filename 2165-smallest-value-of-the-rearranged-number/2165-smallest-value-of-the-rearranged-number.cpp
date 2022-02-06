class Solution {
public:
    long long smallestNumber(long long num) {
        long long ans;
        if(!num) return 0;
        
        string s=to_string(num);
        if(s.front()=='-'){
            //we have to find the largest number without leading zeroe(s)
            
            
            sort(s.begin()+1,s.end(),greater<int>());
            
            return stoll(s); 
        }
        
        //now we are having positive no. , we have to. determine the smallest possible number without leading zeroe(s)
        sort(s.begin(),s.end());
        int n=s.size();
        if(s.front()!='0') return stoll(s);
        int i=0;
        for(;i<n and s[i]=='0';i++){}
        swap(s[0],s[i]);
        return stoll(s);
    }
};