class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmount=0,i=0,j=height.size()-1;
        while(i<j){
            int width=j-i;
            maxAmount=max(maxAmount,width*min(height[i],height[j]) );
            if(height[i]<height[j]) i++;
            else if(height[i] >height[j]) j--;
            else i++,j--;
        }
        return maxAmount;
    }
};

/*
How will you go abput constructing the logic??
try for this test case [1,1,8,1,1,1,1,1,7]
Is this problem an application of simple two pointer 

*/