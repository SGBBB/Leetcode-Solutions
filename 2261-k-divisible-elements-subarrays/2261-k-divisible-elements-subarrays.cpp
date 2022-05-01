struct Node{
    unordered_map<int,Node*> store;
    int cnt=0;
    Node(){}
    int insert(vector<int > &nums,int i,int k,int p ){
        
        if( i== nums.size()  )
            return 0;
        k-=nums[i]%p==0;
        if(k<0) return 0;
        if(store[ nums[i] ]==NULL) 
            store[nums[i]]=new Node();
        int res=store[nums[i]]->insert(nums,i+1,k,p);
        store[nums[i]]->cnt++;
        //If im meeting store[nums[i]] then add it to our ans
        res+=store[nums[i]]->cnt==1;
        return res;
    }
    
};
class Solution {
    
public: 
int countDistinct(vector<int>& nums, int k , int p) {
     Node t;
    int res=0;
    for(int i=0,n=nums.size();i<n;i++){
        res+=t.insert(nums,i,k,p);
    }
    return res;
}
    /*
    Complexity of this solution is n^2 becoz for i=0->(n-1) 
    we can create new trie as well
    
    
    */
};

/*
How will you think about solving this problem ??????
[2 3 3 2 2]

[2 3 3 2 2]

1 thing im sure that people are using some brute force approach to solve this
I will suggest at max 19900 entries can occur inside set data structure
*/