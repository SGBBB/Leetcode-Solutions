class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> deadStates(deadends.begin(),deadends.end()),
        startStates,
        endStates;
        
        startStates.insert("0000");
        endStates.insert(target);
        if(deadStates.count( string(4,'0') ) )
            return -1;
        int level=0;
        while( !startStates.empty() && !endStates.empty()){
            
            set<string> tempStates;
            for(auto &str:startStates){
                
                if(deadStates.count(str))
                    continue;
                deadStates.insert(str);
                if( endStates.count(str) )
                    return level;
                
            
            //If you found some state in the. mid-way then you must return the cnt
            
            string curStr=str;
            for(auto &ch:curStr){
                int num=ch-'0',
                prev_num=(num+10-1)%10,
                next_num=(num+1)%10;
                ch=prev_num+'0';
                if( !deadStates.count(curStr) ){
                    
                    tempStates.insert(curStr) ;
                }
                
                ch=next_num+'0';
                
                if( !deadStates.count(curStr) ){
                    
                    tempStates.insert(curStr) ;
                }
                ch=num+'0';//changing ch to its original position
            } //end of for loop
            
                
            }
            
            
            // update sets
            level++;
            startStates=endStates,
            endStates=tempStates;
        }
        
        return -1;
    }
    /*
    At max I will be ended-up explroring 1000 states.
    0000->
    
    
    On what basis am I making next move????
    
    */
    
    int openLock_method2(vector<string>& deadends, string target) {
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