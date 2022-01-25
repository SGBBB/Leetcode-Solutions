class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len=arr.size();
        if (len<3) return 0;
        int i=1;
        int flag1=0,flag2=0;
        for(;i<len and arr[i]>arr[i-1] ;i++,flag1=1) {}
        if(i==len) return 0;
        
        int pivot=i;
        for(;i<len and arr[i] <arr[i-1];i++,flag2=1){}
        return i==len and flag1 and flag2;
    }
};