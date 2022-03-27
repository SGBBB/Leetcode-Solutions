class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size(),cnt=0 ;
//         for(int i=0;i<nums.size()-1;i++){
//             if(i<nums.size()-1 && !(i&1) && nums[i]==nums[i+1] ){
//                 nums.erase(nums.begin()+i),len--,i--;
//             }
            
//         }
        for(int i=0;i<n-1;){
            if(  i<n-1 && nums[i]==nums[i+1] ){
                i++,cnt++;
            }
            else i+=2;
            
        }
        cout<<cnt<<endl;
        return ( (n-cnt) &1) ?  cnt+ 1  : cnt;
    }
    
//      int minDeletion(vector<int>& nums) 
//     {
//         int cnt=0;
        
//         for(int i=0; i<nums.size()-1; i++)
//             if(((i-cnt)%2==0 && nums[i]==nums[i+1]))
//                cnt++;
//         cout<<cnt<<endl;   
//         if((nums.size()-cnt)%2) cnt++;
               
//         return cnt;
//     }
    
};

/*
1 2 3 3 

if lenght is evn then atleast 2 deletions have to be made
[1, 2 ,2, 2 ,3, 3, 5 ,6]

6,6,6

*/