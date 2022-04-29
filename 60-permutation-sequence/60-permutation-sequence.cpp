int fact[13];
class Solution {
    
string findPermutation(vector<int> &num , int req){
    
    if(num.size() ==0    ){
        return "";
    }
    cout<<"bc "   <<endl;
    int factorial=fact[num.size()-1];
    int idx=req/factorial;
    
    string str=to_string(num[idx]);
    num.erase(num.begin()+idx);
    string res=str+findPermutation(num,req%factorial);
    
    return res;
}
public:
string getPermutation(int A, int B) {
    fact[0]=1;
    for(int i=1;i<13;i++)
        fact[i]=i*fact[i-1];
    vector<int> num;
    for(int i=1;i<=A;i++)
        num.push_back(i);
    return findPermutation(num,B-1);
}
// public:
//     string getPermutation(int n, int k) {
        
//     }
};