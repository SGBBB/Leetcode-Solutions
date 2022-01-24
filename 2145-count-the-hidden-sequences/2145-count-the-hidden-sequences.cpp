class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long low=0,high=0,a=0;//here a is a dead thing which is just helping us to get minimum and maximum values  
        for(int i:differences){
            a+=i;
            low=min(low  , a ),
            high=max(high, a );
        }
        cout<< low<< high<<endl;
        return max(0L , (upper-lower)-(high-low)+1);
    }
};