class KthLargest {
    int k; 
    priority_queue<int,vector<int>,greater<int>> s;
public:
    
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        
        for(int num:nums){
            
            s.push(num );
            if(s.size()>k) s.pop();
        }
    }
    
    int add(int val) {
        if(s.size() <k)  { s.push(val); return s.top();}
        if(!s.empty() && s.top()<val){
        // cout<< "del val is"<<*s.begin()<<" "<<val<<" " ;
            s.pop( );
            s.push(val);
        } 
        return s.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 
 finding kth largest  operation have to be done in constant time complexity.
 So i think we must use 2 heaaps
 first max heap : 3 3 2 
 second min heap:5 5 8 
 next time while appending new element if new guy is smaller than 4 then dont include it in minHeap
 
 */