struct node{
    // int prevCondition,nextCondition;
    int first,second;
    node(int first,int second){
        this->first=first,
        this->second=second;
    }
};
class Solution {
public:
 
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // time--;
        //if time is 0 then return seurity arr as it is
         
        int l = security.size();
        vector<int> ret;
// 5,3,3,3,5,6,2
        vector<node> v(l,node(0,0));
        
        for(int i=1;i<l;i++){
            //if this condition is not fulfilled then discontinuation will happen and v[i].first will be 0 only try to dry run code after some days
            if(security[i]<=security[i-1])
                v[i].first=v[i-1].first+1;
            
            if(security[l-i]>=security[l-i-1])
                v[l-i-1].second=v[l-i].second+1;
        }
            

        for(int i = 0; i < v.size(); i++) {
            //if at any moment both side conditions are followed then push it into our data structure 
            if(v[i].first >= time and v[i].second >= time) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
/*

How will i go ahead solving this prblem????
Observations:
1. All test cases are subtle and enough to think a solution 
and 1 guy willa lways follow every condition
5,3,3,3,5,6,2

prefix array

1 2 3 4 1 1 2

until i sequence must be decresing order
after i sequence must be increasing order

(Q) Can i state that if time == 0 then return seurity arr as it is ????
ya

I can sense that some prefix  and sufix arr will be used  to solve this

Can there be edge case when time > security.size()????

while moving from i till n-time we wil perform some sliding window stuff
while moving from n-1 till >=time we wil perform some sliding window stuff


*/