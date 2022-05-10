class MedianFinder {
    public:
        MedianFinder() { }

    priority_queue<int> maxHeap;
    multiset<int> minHeap;
    
    
    void addNum(int num) {
        //Connecting such that maxHeap is placed before minHeap
        //initially I'm. ensuring  let's insert value in maxHeap or if value is less than maxHeap ka top value then insert it to maxHeap else insert it to minHeap.  
        if( maxHeap.empty() || num <maxHeap.top() ) maxHeap.push(num);
        else minHeap.insert(num);
        //if the maxHeap.size() went too bigger than minHeap then do transfer the element from maxHeap to minHeap.
        if( maxHeap.size() >minHeap.size()+1     ) 
            
            minHeap.insert(maxHeap.top()) , maxHeap.pop() ;
            
        else if(minHeap.size() > maxHeap.size() +1) 
            maxHeap.push( *minHeap.begin() ), minHeap.erase( minHeap.begin() ) ; 
    }
    double findMedian() {
        //if size of both heaps is same then that means overall size is even . so median will be average of maxHeap.top() and minHeap.top()
        if(minHeap.size()==maxHeap.size()  ) 
            return   (double )(maxHeap.top()+ *minHeap.begin() )/2; 
        //else if there exists difference between the size of both the heaps then ans will be top guy of the larger size heap
        else if( maxHeap.size() > minHeap.size() ) return (double) maxHeap.top() ;
        return (double) *minHeap.begin() ;
    }
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */