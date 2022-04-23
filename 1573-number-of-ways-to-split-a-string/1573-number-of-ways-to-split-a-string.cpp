class Solution {
public:
    //This problem seems to be of sucking observation flavour
    int numWays(string s) {
        long long mod=1000000007;
        long long sum=0,len=s.size();
        for(auto it:s){
            sum+=it-'0';
        }
        if(sum%3) return 0;
        if(!sum){//sum is 0
        cout<<" sum. is "<<sum<<endl;
            //Design a new formula which will give ans in constant time complexity
            return (( (len-1)*(len-2)*1LL )/2)%mod ;
        }
        //now sum is multiple of 3
        long long s1=0,cntLeft=1;
        for(auto ch:s) {
            s1+=ch=='1'; 
            
            if(s1>sum/3) break;
            else if (s1==sum/3) cntLeft+=ch=='0';
        }
        reverse(s.begin(),s.end());
        long long s3=0,cntRight=1;
        for(auto ch:s) {
            s3+=ch=='1'; 
            
            if(s3>sum/3) break;
            else if (s3==sum/3) cntRight+=ch=='0';
        }
        return (cntLeft*cntRight*1LL)%mod;
    }
    
};
/*
"10101"
How to decipher this problem? 

1 0 1 0 1



*/