class Solution {
    // sides->{U,D,L,R}
    bool backtrack(vector<int>& matchsticks, vector<int> &sides,int start=0){
        int n = matchsticks.size();
        
        if(start==n && !max( {sides[0],sides[1],sides[2],sides[3]} )  ){
            
            // return true only when value of all sides is 0
            cout<<sides[0]<<" "<<sides[1]<<" "<<sides[2]<<"  "<<sides[3]<<endl;
            return true;
        }
        // for(int i=start;i<n;i++){
            for(int k=0;k<4;k++){
                if(sides[k]-matchsticks[start]<0)
                    continue;
                sides[k]-=matchsticks[start];
                bool response=backtrack(matchsticks,sides,start+1);
                if(response==true)
                    return true;
                sides[k]+=matchsticks[start]; //undo step get back the previous state of sides array
                
            }
        // }
        return false;
    }
public:
    /*
    You have to consider each combinations and check whether sum of every formed 4 stick's are smae  and all sticks are consumed.
    
    
    */
    bool makesquare(vector<int>& matchsticks) {
        //Base Case : if matchsticks.size()<4 || sum%4 is not zero then it will be impossible to formresulting square
        int sum=0;
        for(int stick:matchsticks)
            sum+= stick;
        if ( matchsticks.size()<4 || sum%4)
            return false;
        //Decresingly sorting becoz there are large length matches and these matches might be larger than side of resulting square
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int> sides({{sum/4,sum/4,sum/4,sum/4}});
        return backtrack(matchsticks,sides);
        //time Complexit y is 4^n
    }
};