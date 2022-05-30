class Solution {
public:
    /*
    At max I will be ended -up explroring 1000 states.
    0000->
    
    
    On what basis am I making next move????
    
    */
    int openLock(vector<string>& deadends, string target) {
        set<string> S(deadends.begin(),deadends.end());
        queue<vector<string>>q; //{states,cnt}
        q.push({"0000","0"});
        if(S.count( string(4,'0') ) )
            return -1;
        S.insert( string(4,'0') );
        while( !q.empty() ){
            vector<string> frontArray=q.front();
            
            q.pop();
            cout<<frontArray[0]<<endl;
            if(frontArray[0]==target)
                return stoi(frontArray[1]);
            
            for(auto &ch:frontArray[0]){
                int num=ch-'0',
                prev_num=(num+10-1)%10,
                next_num=(num+1)%10;
                ch=prev_num+'0';
                if( !S.count(frontArray[0]) ){
                    q.push({ frontArray[0], to_string(stoi(frontArray[1])+1)  });
                    S.insert(frontArray[0]) ;
                }
                
                ch=next_num+'0';
                
                if( !S.count(frontArray[0]) ){
                    q.push({frontArray[0], to_string(stoi(frontArray[1])+1)  });
                    S.insert(frontArray[0]) ;
                }
                ch=num+'0';//changing ch to its original position
            } //end of for loop
        }
        return -1;
    }
};