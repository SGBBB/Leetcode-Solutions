vector<int> sequentialDigits(int low, int high) {
vector<int> ans;
for(long int i=1,start=12, step=11;i<=9;
i++,start= (start*10 ) + (start%10)+1,step=(step*10 )+1 ){
long j=start;
for( ; j<=high and j<pow(10,i+1);j+=step){
ans.push_back(j);
}
}
return ans;