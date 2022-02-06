class Bitset {
public:
    //just take counter of set bits, not that of unset bits as it's not asked here
    int cnt_set=0,n=0;
    bool is_flipped=false;
    string s;
    Bitset(int size) {
        s=string(size,'0');
        n=size,cnt_set=0;
    }
    //these below 3 functions can mutate string
    void fix(int idx) {
        if(!is_flipped) {
            if(s[idx]=='1') return;
            s[idx]='1';
            cnt_set++;
            
            return;
        }
        //is_flipped is true
        if( s[idx]=='0' ) { return ;}
        s[idx]='0';
        cnt_set++;
    }
    
    void unfix(int idx) {
        if(!is_flipped) {
            if(s[idx]=='0') return;
            s[idx]='0';
            cnt_set--;
            
            return;
        }
        //is_flipped is true
        if(s[idx]=='1') return;
        
        s[idx]='1',cnt_set--;
    }
    
    void flip() {
        is_flipped=!is_flipped ,cnt_set=n-cnt_set;
        
    }
    //iske niche saari values ko return krre h bs
    bool all() {
        return (cnt_set)==n;
    }
    
    bool one() {
        return cnt_set>=1;
    }
    
    int count() {
        return cnt_set;
    }
    //this will not cause tle
    string toString() {
        string res=s;
        if(!is_flipped ) return s;
        for(char &ch:res){
            ch=(ch=='1') ?'0':'1' ;
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 null, null, null, null, false, null, null, true, null, 2, "01010"
 */