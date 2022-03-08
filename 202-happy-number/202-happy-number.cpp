

class Solution {
    int next(int n)
    {
        int sum = 0;
        
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        return fast == 1 ;
    }
//     bool isHappy(int n,int prev=-1,bool flag=0) {
//         int temp=n;
//         if(n>1) {
//             int ans=0;
//             for(;n; n/=10 ){
//                 ans+=pow(n%10,2);
                
//             }
//             cout<< temp<<" "<<ans<<endl;
            
            
//             return isHappy(ans,(!flag)?ans:prev,(!flag)?(!flag):flag);
            
//         }
        
//         return n==1; 
//     }
};
/*
Points to ponder:
1.How u'll check that there is cycle or not??
2. upr vale staremtn ko justify kse kruuu ,if there is a cycle then same no. is gonna repeat itself               

*/