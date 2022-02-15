class Solution {
    int f(vector<int>& v,int div){
        int sum=0;
        for(int x:v){
            sum+=ceil(x/div);
            if((x % div)!=0) sum++;
        }
        return sum;
    }
public:
    int  smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=*max_element(nums.begin(),nums.end()),ans=h;
        for(;l<=h;){
            int m=l+(h-l ) /2 ,res=f(nums,m);
            cout<<"res is "<<res<<endl;
            if(res<=threshold)  {//your sum is  lesser than threshold so you try to increase your sum 
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};