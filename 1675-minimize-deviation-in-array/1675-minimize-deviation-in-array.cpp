class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int > pq,pq1;
        int mini=INT_MAX,res=INT_MAX;
        for(int &i:nums){
            i=(i & 1 ) ? 2*i : i ;
            pq.push(i);
            mini=min(mini,i);
            
        } 
        // for(;pq.size();pq.pop()){cout<<pq.top()<<endl;}
        res=min(res,pq.top()-mini); //8 
        ///steps u can appply 110000 
        for(;!(pq.top() & 1);){
            int top=pq.top();
            pq.pop();
            pq.push(top/2);
            mini=min(mini, top/2), res=min(res,pq.top()-mini); // 2
            cout<<pq.top() <<"  "<<mini<<" "<<res<<endl; 
            
        }
        return res;
    }
};

// 10 10  6   4 2


// is it full proof that 2 will always lie as minimum element