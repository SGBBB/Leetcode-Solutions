class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        /*
        
        
        push initial people to queue
        
        */
         
        
        vector<int> values={1,2,3,4,5,6,7,8,9};
        // iterating over n length for each prior set vector
        for(int i=2;i<=n;i++){
            vector<int> tempArr;
            
            for(auto it:values){
                int lastNum=it%10;
                //adding vallid lastNum+k 
                if(lastNum+k<=9)
                    tempArr.push_back(it*10+lastNum+k);
                //adding vallid lastNum-k 
                if(k>0 && lastNum-k>=0)
                    tempArr.push_back(it*10+lastNum-k);
                
                
            }
            values=tempArr;
            
        }
        return values;
        
    }
    /*
    11
    22
    3
    4
    5
    6
    7
    8
    9
    
    */
};