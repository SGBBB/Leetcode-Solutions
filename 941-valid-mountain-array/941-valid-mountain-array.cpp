class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len=arr.size();
        if (len==2 ) return false;
        int i=0,j=len-1;
        for(;i<len-2 and arr[i] < arr[i+1];i++){}
        for(;j-1>0 and arr[j]<arr[j-1];j--){}
        return i>0 and j<len-1 and i==j; 
    }
};