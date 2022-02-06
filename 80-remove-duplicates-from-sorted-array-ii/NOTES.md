int removeDuplicates(vector<int>& nums) {
int val=nums.front(),cnt=0,ans=0,n=nums.size(),idx=0;
for(int i:nums){
if(i==val )cnt++;
else{
val=i,cnt=1;
}
ans+=(cnt<=2);
}
cout<<ans<<endl;
return ans;
}