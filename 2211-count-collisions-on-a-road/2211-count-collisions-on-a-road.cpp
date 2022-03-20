class Solution {
public:
    int countCollisions(string directions,int i=0,int j=0) {
        int n=directions.size();
        j=n-1;
        while(i<n and directions[i]=='L' )   i++; 
        
        while(j>-1 and directions[j]=='R')  
            j--;
        int cnt=0;
        cout<<i<<j<<endl;
        while(i<j+1){
            cnt+=( directions[i]!='S' );
            i++;
        }
        return cnt;
    }
};