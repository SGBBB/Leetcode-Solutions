class Solution {
public:
    int addDigits(int num) {
        if(num/10){
            int temp=num,sum=0;
            for(;temp;sum+=(temp%10), temp/=10){}
            return addDigits(sum);
            
        }
        return num;
    }
};