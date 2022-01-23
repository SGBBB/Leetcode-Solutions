class Solution {
    vector<int> ans;
    void recursion(int low,int high,int n,int i){
        if(n>=low and n<=high) ans.push_back(n);
        if(i<=9 and n<=high){
            
            
            n=(n*10)+i;
            recursion(low,high,n,i+1);
        }
        
        
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        ans.clear();
        for(long int i=1 ;i<9;i++){
            recursion(low,high,i,i+1);//9*9
        }
        sort(ans.begin(),ans.end() );//nlogn
        return ans;
    }
};