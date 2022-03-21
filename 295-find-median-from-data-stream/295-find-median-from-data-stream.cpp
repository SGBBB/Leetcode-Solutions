class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() { }
    void addNum(int num) {
        //initially I'm. ensuring that  let's insert value in maxHeap or if valuen is less than maxHeap ka top value then insert it to maxHeap else insert it to minHeap.  
        if( maxHeap.empty() || num <maxHeap.top() ) maxHeap.push(num);
        else minHeap.push(num);
        //if the maxHeap.size() went too bigger than minHeap then do transfer the element frommaxHeap to minHeap.
        if( maxHeap.size() >minHeap.size()+1     ) 
            //do something
            minHeap.push(maxHeap.top()) , maxHeap.pop() ;
            
        else if(minHeap.size() > maxHeap.size() +1) 
            maxHeap.push(minHeap.top() ),minHeap.pop() ; 
    }
    double findMedian() {
        //if size of both heaps is same then that means both heaps has even size so overall size is even too so median will be average of maxHeap.top() and minHeap.top()
        if(minHeap.size()==maxHeap.size()  ) 
            return   (double )(maxHeap.top()+minHeap.top() )/2; 
        //else if there exists difference between the size of both the heaps then ans will be top guy of the larger size heap
        else if(maxHeap.size() >minHeap.size()) return (double)maxHeap.top() ;
        return (double)minHeap.top() ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */