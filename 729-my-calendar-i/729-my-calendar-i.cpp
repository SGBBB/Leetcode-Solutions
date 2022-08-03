class MyCalendar {
    /*
    
    Knowing whether slot is available or not has to be done in constant time complexity.
    
    10 11 12 13 14 15 16 17 18 19 
    
    10 19   <--let this pair sit in our data structure
      15 24 <--striped off kr isko
         20  29 <--let this pair sit in our data structure
    
    1  9 
    14 15
    10 19
    15 24
     
    20 29
    
    
    10 19
    (15 25)
    20 29
    
    
    1 3
    3 4
    [1 3]
    
    */
    set<vector<int>> S;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto  nextPair=S.upper_bound({start,end});
         
        if(nextPair!=S.end() ){
            vector<int> arr=*nextPair;
            if( arr[0]<end) return false;
        }
        if(nextPair!=S.begin() ) {
            vector<int> arr=*(--nextPair);
            if(  start<arr[1])
                return false;
        }
        S.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */