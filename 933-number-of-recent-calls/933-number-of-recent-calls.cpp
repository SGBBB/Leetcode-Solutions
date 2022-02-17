class RecentCounter {
    queue<int> q;
    int counter=0;
public:
    RecentCounter() {
        counter=0;
    }
    
    int ping(int t) {
        q.push(t);
        int time=max({0,t-3000});
        for( ; q.size() and q.front()<time ; q.pop() ){    }        
        return q.size() ;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */