class Solution {
public:
    bool canChange(string start, string target) {
        /*
        
        _L__R__R_       
        
        _L____R_R
        
        
        R_L_
        _LR_
        
        __LR
        
        
        
        
        minor sa case
        _L
        L_
        */
       
        queue< vector<int> > startString, targetString;
        int n=start.size();
        for(int i=0;i<n;i++){
            if(start[i]=='_')
                continue;
            // Left ko 0 se represent krre h and right ko 1 se
            int direction=start[i]=='L'?0:1;
            
            startString.push(vector<int>({direction,i}));
            
        }
        
        for(int i=0;i<n;i++){
            if(target[i]=='_')
                continue;
            // Left ko 0 se represent krre h and right ko 1 se
            int direction=target[i]=='L'?0:1;
            
            targetString.push(vector<int>({direction,i}));
        }
        //both strings doesnt have equal direction characters
        if(startString.size()!=targetString.size())
            return 0;
        while(!startString.empty()){
            vector<int> startVector=startString.front(),
                        targetVector=targetString.front();
            startString.pop();
            targetString.pop();
            //both the directions arent equal simply return false;
            if(startVector[0]!=targetVector[0])
                return 0;
            //If current direction char is left
            if(startVector[0]==0 && startVector[1]<targetVector[1]  )
                return 0;
            //If current direction is right
            else if(targetVector[0]==1 && startVector[1]>targetVector[1])
                return 0;
                
        }
             
        // Left ko 0 se represent krre h and right ko 1 se
        
        return 1;
    }
};