class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,n1=version1.size(),n2=version2.size() ,res;
        string s1 ="",s2=""  ;
        for(i=0,j=0;i<=n1 or j<=n2;i++,j++){
            while(i<n1 and (version1[i]!='.' )  ){
                s1+=version1[i++];
            }
            while(j<n2 and (version2[j]!='.' )){
                s2+=version2[j++];
            }
            res=(stoi(s1) ==stoi(s2)) ? 0: (stoi(s1) >stoi(s2)) ? 1: -1;
            if(res) return res;
            s1="0",s2="0"; 
            // empty s1 and s2
            
            
        }
        return res;
    }
};