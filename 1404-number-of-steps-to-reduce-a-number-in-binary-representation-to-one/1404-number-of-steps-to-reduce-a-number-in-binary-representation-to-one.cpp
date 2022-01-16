class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1){
            if(!s.empty() and s.back()=='0' ){ //check for even digit 
                s.pop_back();
            }
            else{ //check for odd digit
                for(;s.size() and s.back()=='1';ans++,s.pop_back()){}
                if(!s.empty() ) s.back()='1';
                else return ans+1;
                
            }
            ans++;
        }
        return ans;
    }
};