class Solution {
    /*
    [2,2,2] ->3
    [2,2,2,2]->6
    If x+1 rabbits have same color, then we get x+1 rabbits who all answer x.
    try to operate same color people simultaneously.
    
    
    10
    
    
    [[4,4,4,4,4],           [4]]
    [4,4,4,4,4,     4,4,4,4,4,      4] ->5+5+5
    */
public:
    int numRabbits(vector<int>& answers) {
        map<int , int> answers_cnt;
        for(int answer:answers){
            answers_cnt[answer]++;
        }
        int totalRabbits=0;
        for(auto it:answers_cnt){
            int cur_answer=it.first,cur_answer_cnt=it.second;
            
            
            
            totalRabbits+= (cur_answer+1)*(cur_answer_cnt/(cur_answer+1));
            //if mod is non zero 
            if(cur_answer_cnt%(cur_answer+1)!=0){
                totalRabbits+=cur_answer+1;
            }
                
        }
        cout<<totalRabbits<<endl;
        return totalRabbits;
    }
};