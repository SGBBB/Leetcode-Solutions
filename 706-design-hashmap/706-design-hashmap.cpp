class MyHashMap {
    vector<list< pair<int,int> >>m;
    int len=1001;
public:
    MyHashMap() {
        m.resize(len);
    }
    int generateHashCode(int key){
        return key%len;
    }
    void put(int key, int value) {
        int idx=generateHashCode(key);
        
        //whether I already have key-val pair then delete  it
        remove(key);
        
        m[idx].push_back({key,value});
    }
    list< pair<int,int> > :: iterator search(int key){
        int idx=generateHashCode(key);
        list< pair<int,int> > :: iterator it=m[idx].begin();
        for(;it!=m[idx].end();it++){
            if(it->first==key  )  return it;
        }
        return it;
    }
    int get(int key) {
        auto it=search(key);
        int idx=generateHashCode(key);
        //remove if its already present
        
        if( it==m[idx].end() ) return -1;
        //now I'm having the key-val pair inside my data structure
        return it->second;
    }
    
    void remove(int key) {
        auto it=search(key);
        int idx=generateHashCode(key);
        if( it==m[idx].end() ) return ;
        //now I'm having the key-val pair inside my data structure
        m[idx].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */