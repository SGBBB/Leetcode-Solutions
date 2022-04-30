class Solution {
    //time complexity is O(n^2).
public:
    vector<int> grayCode(int n) {
        if(n==1) 
            return {0,1};
        vector<int> ans;
        vector<int> codes=grayCode(n-1);
        int pos=n-1;
        for(int num:codes){ 
            ans.push_back(num);
        }
        reverse(codes.begin(),codes.end());//O(n)
        for(int num:codes){
            int temp=num;
            temp=temp ^ (1 << pos);
            cout<< "temp is " << temp<<endl;
            ans.push_back(temp);
            
        }
        
        
        return ans;
    }
};
/*
How to proceed in such problem????




n(2)   00 10    11   01
How will you know that 2 or 1 will come after 0
Consider that initially "00" is given to you
00->01->11->10
00->10->11->01
recursion failth vala concept is used here
*/