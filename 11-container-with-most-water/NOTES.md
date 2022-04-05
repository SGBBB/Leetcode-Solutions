class Solution {
public:
int maxArea(vector<int>& height) {
int start=0,maxHeight=0,n=height.size(),l=0,w=0,maxArea=0;
vector<int> L(n),R(n);
for(int i=1;i<n;i++){
l=min(maxHeight,height[i]);
w=abs(i-start);
L[i]=l*w;
if(height[i]>maxHeight){
maxHeight=height[i];
start=i;
}
maxArea=max(maxArea,L[i]);
}
// cout<<maxArea<<endl;
start=n-1,maxHeight=height[n-1],maxArea=0;
for(int i=n-2;i>=0;i--){
l=min(maxHeight,height[i]);
w=abs(i-start);
R[i]=l*w;
if(height[i]>maxHeight){
maxHeight=height[i];
start=i;
}
maxArea=max(maxArea,R[i]);
}
// cout<<endl<<maxArea<<endl;
return maxArea;
}
};