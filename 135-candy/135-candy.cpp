class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
        
        
        1,0,2
        2 1 2
        
        Algo:
        Initially fill array with all 1
        Iterate from left to right 
        Iterate from right to left
        
        
        Ther will be ratings.size() candies atleast.
        
        [1,3,2,2,1]
         1 2 1 1 1
         1 2 1 2 1
        
        
        
        [1,2,87,87,87,2,1]
         1 2  2 1  1  1 1 
         1 1  1 1  2  1 1
         
         
         1 1  1 1  2  1 1
         
         
         
         5 6 7 8 7
         1 2 3 4 1
         
         1 2 3 4 1 
         
         
         5 6 7 9 7 8
         1 2 3 4 1 2
         
         testcase
         5 6 7
         
         testcase
         5 6 7 8 7 4 3 1 2  
         
         1 2 3 4 1 1 1 1 2
         1 2 3 5 4 3 2 1 2
         
         ans
         1 2 3 5 4 3 2 1 2
         
         
          
         
         5 ,6 ,7 ,8 ,7, 4 ,3 ,1, 2  
         
         
         
        */
        
         
        int cookieCnt=0,n=ratings.size();
        vector<int> leftToRight(n,1),rightToLeft ;
        //left to right scan its a greedy scan think about case->[5,6,7]
        for(int i=1;i<n;i++){
            leftToRight[i]=(ratings[i]>ratings[i-1])?leftToRight[i-1]+1:leftToRight[i];
        }
        rightToLeft=leftToRight;
        //right to left scan
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                
                rightToLeft[i]=max( {rightToLeft[i+1]+1 , rightToLeft[i]} );
        }
         
        
        for(int i=0;i<n;i++){
            cookieCnt+= rightToLeft[i];
        }
//         return cookieCnt+ratings.size();
        return cookieCnt;
    }
};