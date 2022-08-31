class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        /*
        
        2,2,2,1,2,1,2,1,2
        
        2
        3
        
        
        1 2 1 2 1 1 1 3
        
        
        1, 2, 4, 4, 4, 4
        
        */
        int count=0; //counter variable
        for(int i=0;i+m<arr.size();i++) // i+m<arr.size() because ith value is compared to i+m th value
        {
            if(arr[i]!=arr[i+m])//if not equal conuter is reset,as ques requires consecutive pattern
                count=0;
            else
                count++; //if same.. counter increases
         //k-1 is beacuse the last pattern is not compared to next.. as it is the last ..after that the               counter resets itself   
        if(count==(k-1)*m) 
            return true;
            
        }
        return false;
    }
};