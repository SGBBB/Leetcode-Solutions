int powers[22];
class Solution {
    
    
public:
    int countPairs(vector<int>& deliciousness) {
        long long mod=1e9 + 7,cnt=0; 
        powers[0]=1;
        for(int i=1;i<22;i++){
            powers[i]=powers[i-1]*2;
            // cout<<i<<" "<<powers[i]<<endl; 
        }
        
        unordered_map<int,int> M;
        for(int num:deliciousness){
            for(int k=0;k<22;k++)
                if(powers[k]>=num && M.count(powers[k]-num) )
                    { cnt+=M[powers[k]-num];}
            
            M[num]++;
        }
        
        
        return cnt%mod;
        //Time complexity:O(n*20) = O(n) approx
    }
};
/*

How will i move ahead in this problem????
1 3 5 7 9

1 3 ->4
1 7 , 3 5,  ->8
7 9 ->16

should i store all powers of 2 until 2^20.

1,1,1,3,3,3,7



another eg:
1 3 5 3 7 9

[1 ,3, 5 ,3 ,7, 9]


[0, 1 ,1]
0 1,0 1
1 1
cnt=3

Should i submit code now???
Im 90 % confident about my algorithm
but wanna check few cases as well before submitting.


*/