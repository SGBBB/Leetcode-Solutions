class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> M;
        for(int it:tasks){
            M[it]++;
        }
        int ways=0;
        for( auto [val,cnt]:M ){
//             if freq of any guy is <2 then return {-1};
            if(cnt<2) return -1;
            // now cnt is greater than 2
            ways+=(cnt/3);
            ways+=( cnt%3 > 0 ); 
        }
        return ways;
    }
};
/*

 How will I go about solving thi sproblem???
 
 2,2,3,3,2,4,4,4,4,4
 
 2,2,2,3,3,4,4,4,4,4
 Initially try to cnt freq of each digit 
if any task is present of freq  1 return -1

should i sort the given arr
if im sorting the given arrr then i need to think about how will i manage freq correspoondign to every guy

Leave sorting the arrr just use a hashmap to achieve this
Then i need to think greedily about this problem

if any guy's freq is <2 then return -1;
2 2 3 3 3 3 3 3 3
if freq of 3 is 10 then ???
10/3 =2
10%3=1
1+3=4

mod value can range btw 0,1,2 

*/