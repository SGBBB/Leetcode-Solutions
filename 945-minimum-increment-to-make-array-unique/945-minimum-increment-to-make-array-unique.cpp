class Solution {
public:
    /*
    
    1 2 2
    
    
    3 2 1 2 1 7
    1 1 2 2 3 7
    
    1 2 3 2 3 7
    1 2 4 5 3 7
    
    
    
    I think its somewhat related to frequency of elements
    
     
    
    Algo Walkthrough:
    Step1: At every iteration I require minimum element with minimum frequenncy this will be the desired guy at every iteration 
    If freq of my desired guy is 1 then insert it into my vector .
    
    perform step1 until size of vector becomes equal to n.
    
    
    */
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int,int> M;//{digit,freq}
        for(auto it:nums){
            M[it]++;
        }
        set < vector<int> > S; //format of vector {digit,freq}
        for(auto it:M){
            S.insert({it.first,it.second});
        }
        int operation_cnt=0;
        while(!S.empty()){
            auto topGuy=*S.begin();
            int val=topGuy[0],
                freq=topGuy[1];
            
            S.erase( S.begin() );
            // cout<< "topGuy is  "<<val<<" "<<freq<<endl;
            if(freq==1){
                continue;
            }
            //now freq is surely greater than 1
            
            int cnt=freq-1;
            operation_cnt+=cnt;
            if(!S.empty() && ( *S.begin() )[0]==val+1 ){ //if sec top guy exists
                auto secTopGuy=*S.begin();
                int val2=secTopGuy[0],
                freq2=secTopGuy[1];
                S.erase( S.begin() );
                S.insert({val2,freq2+cnt});
                
                
            
            }
            else{
                S.insert( {val+1,cnt} );
            }
            
            S.insert( {val ,1} );
            
                
        }
        return operation_cnt;
        
    }
};