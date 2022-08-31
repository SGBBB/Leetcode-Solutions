class Solution {
    vector<int > getFreq(int num){
        vector<int> M(10); //0....9 is 10 in total
        while(num){
            M[num%10]++;
            num/=10;
        }
        return M;
    }
public:
    bool reorderedPowerOf2(int n) {
        /*
        232
        1 2 4 8 16 32 64 128 256 512 1024 2048 4096
        31 elements will be there 
        checking whtehr its power of 2 will take const timne
        
        
        consider a positive case
        1042  (1024)  2^10
        
        64    1000000
        32     100000
16 10000
8   1000
4   
        1048576 2^20
        
        Intuition: There will not be more than 10 digits 
        
        Checking for permutation s   is  wasting a lot of resources
        So, lets make use of  existing 10 digits we have got
        
        
        
        
        */
        //  freq store of 2 ki piowers will not  more then 30 size * 10 is max size of n
        //time complexity will not be more than 10*30
        for(int i=0;i<31;i++){
            vector<int>curPowerOf2 =getFreq(1<<i );
            int num=n;
            //Reducing the freq of eacxh digit in nums
            while(num){
                curPowerOf2[num%10]--;
                 
                num/=10;
            }
            int flag=1;
            //Check whether given num resembles to any power of 2 or not
            for(auto it:curPowerOf2){
                if(it!=0){
                    flag=0;break;
                }
                    
            }
            if(flag)
                return 1;
        }
        return 0;
    }
};