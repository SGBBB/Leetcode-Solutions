class SmallestInfiniteSet {
    set<int> S;
    
    queue<int >q;
     
public:
    SmallestInfiniteSet() {
        
         
        for(int i=1;i<=1000;i++){
            S.insert(i);
        }
      
    }
    
    int popSmallest() {
        int front=*S.begin();
        cout<<"POP "<< front <<endl;
        S.erase(S.begin());
        return front;
         
    }
    
    void addBack(int num) {
        S.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */