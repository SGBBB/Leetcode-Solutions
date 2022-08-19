class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /*  1 2 3 3 4 5
        
        1 2 3 
        3 4 5
        
        
            1 2 3 4 5 
            
        
        1 2 3 4 4 5
        false
         
        1 3 4 4 5 6
         
        1 2 3 3 4 4 5 5 6 6
        Justification:
        1 1
        2 1
        3 2
        4 2
        5  2
        6 2
        
        1
        
        1 2 3 4 5 6
        3 4 5 6 
        
        1 1 1 2 2 2 3 3 3 4 4 5
        1 3
        2 3
        3 3
        
        1 2 3 4 5 
        1 2 3 4
        1 2 3
        
        */int n=nums.size();
        unordered_map<int,int> availability_map,vacancy_map;
        //getting freq of each integer
        for(int i=0;i<n;i++){
            availability_map[nums[i]]++;
        }
        /*
        Every guy has got 2 options:
        1. either get concatenated with some series 
        2. or start new sequence with atleast 3 chars
        
        */
        for(int i=0;i<n;i++){
            // check whetherh current no. doesn't exists in availability_map
            if(!availability_map.count(nums[i])){
                continue;
            }
            //now current no. exists in availability_map
            availability_map[nums[i]]--;
            if(!availability_map[nums[i]])
                    availability_map.erase(nums[i]);
             // check whetherh current no.   exists in vacancy_map
            if(vacancy_map.count(nums[i])){
                vacancy_map[nums[i]]--;
                if(!vacancy_map[nums[i]])
                    vacancy_map.erase(nums[i]);
                vacancy_map[nums[i]+1]++;
            }
            //if current num doesnt exists in vacancy map then he needs to start his own sequence
            else if ( availability_map.count(nums[i]+1) && 
                    availability_map.count(nums[i]+2) ){
                
                availability_map[nums[i]+1]--,
                availability_map[nums[i]+2]--;
                if(!availability_map[nums[i]+1])
                    availability_map.erase(nums[i]+1);
                if(!availability_map[nums[i]+2])
                    availability_map.erase(nums[i]+2);
                
                //creating vacancy for nums[i]+3
                
                vacancy_map[nums[i]+3]++;
            }
            // if current num isnt capable of starting his own sequence also then return false;
            else {
                return false;
            }
        }
        //if everything went right then return true
        return true;
    }
};