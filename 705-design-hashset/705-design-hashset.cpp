class MyHashSet { 
    //The intend of this problem is to know whether candidate know internal implementation of ahshset?
    int len=1000;
    
public:
    vector<list<int>> m;
    MyHashSet() {
        m.resize(len);
    }
    int generateHashCode(int key){
       return key%len; //O(1)
    }
    list<int> ::iterator search(int key ){
        int idx=generateHashCode(key);
        return find(m[idx].begin(),m[idx].end(),key);
    }
    void add(int key) {
        
        if( contains(key) ) return ;
        int idx=generateHashCode(key);
        m[idx].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))  return;//If key isnt present then I can't remove it
        //Now key is inside vector
        int idx=generateHashCode(key);
        auto it=search(key);
        m[idx].erase(it);
    }
    
    bool contains(int key) {
        int idx=generateHashCode(key);
        return search(key )!=m[idx].end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */