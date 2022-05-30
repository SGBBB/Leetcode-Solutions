map<vector<int> ,int> stored_states;
class Solution {
    
public:
    
    /*
    [2,3,4]
    
    [1,1,0,4]
    [2,2,1,9]
    
    [1,2,1]
     
     price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
     
     
     (3,2)
     
    I think special array we hav eto save in map only 
    
    */
    
int shoppingOffers(vector<int>& price, vector<vector<int>>& special,vector<int> &needs) {
        
        int n=price.size();
        int min_cost=0;
    
        for(int i=0;i<n;i++){
            min_cost+=(price[i]*needs[i]);
        }
         
        // Iterating to each special offers 
        for(auto it:special){
            
            int flag=1;
            for(int i=0;i<n;i++){
                if(it[i]>needs[i]){
                    flag=0; break;  
                }
                    
            }
            // current discount isnt appropriate
            if (!flag)
                continue;
            
            // now cur shopping offer is appropriate
            for(int i=0;i<n;i++){
                needs[i]=needs[i]-it[i];
            }
            int cur_cost=it[n] +shoppingOffers(price,special,needs);
            min_cost=min( { min_cost,cur_cost } );
            //undoing backtracking step 
            for(int i=0;i<n;i++){
                needs[i]=needs[i]+it[i];
            }
            
        }
        stored_states[needs]=min_cost;
        return min_cost;
        
    }
    /*
    [1,1,1]
[[1,1,0,0],[2,2,1,0]]
[1,1,1]

    
    */
};