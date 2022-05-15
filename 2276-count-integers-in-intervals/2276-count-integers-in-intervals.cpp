class CountIntervals {
    int lastCnt;
    map<int,int>  events;
public:
    CountIntervals() {
        lastCnt=0;
    }
    
    void add(int left, int right) {
        events[left]++,
        events[right+1]--,
        lastCnt=-1;//If you updated your event sthen surely you again have to make fresh cnt
    }
    
    int count() {
        int flag=0,start=0;
        //if lastCnt==-1 that means it needs some processing
        if(lastCnt==-1){
            
            map<int,int>  newEvents;
            lastCnt=0;//reset lastCnt to store fresh  cnt
            for(auto it:events){
                //This means that we are at start of some interval
                if(flag==0)
                    start=it.first,newEvents[start]++ ;
                
                flag+=it.second;
                //This means we are at end of interval
                if(flag==0)
                    lastCnt+=(it.first-start),newEvents[it.first]--;
            }
            events=newEvents;
            
        }
        return lastCnt ;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */