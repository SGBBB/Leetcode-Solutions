class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // set<int> participants;
        vector<int> participants(100002,-1);
        int big_guy=0;
        for(auto it:matches){
            big_guy=max( {big_guy,it[0],it[1]} );
            if(participants[it[0]]==-1)//if it[0] is not -1 then i'll even not touch it
                participants[it[0]]=0;
            // else participants[it[0]]++;
            if(participants[it[1]]==-1)
                participants[it[1]]=1;
            else participants[it[1]]++;
            
        } 
        priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>  
            pq;
        
        participants.resize(big_guy+1);
        for(int i=0;i<big_guy+1;i++){
            if(participants[i]==-1) continue;
            pq.push({participants[i],i});
        }
        vector<int> not_lost;
        while(!pq.empty() && !pq.top().first){
            not_lost.push_back(pq.top().second);
            pq.pop();
        }
        vector<int>lost_once;
        while(!pq.empty() && pq.top().first==1){
            cout<<pq.top().first<<pq.top().second<<endl;
            lost_once.push_back(pq.top().second);
            pq.pop();
            
            // if(pq.top().first>1) {cout<<"came ?"<<endl;break;}
        }
        //now priority pq  doesnt holds elements having loose _count = 0
        
        return {not_lost,lost_once};
    }
};

/*
1 0
2 0
3
4
5
6
7

8
9
10

how will i approach this porblme??
Requirement
1.find the guys who have not lost any match
2. find the guys who have lost just 1 match

Approach comping to my brain:
use a set named "participants" to gather all people while iterating over matches 2d array ,so that i dont hold any duplicate guy this will tell me how whichever guys did participated in mathch

map use kru ky???
map<times_he_lost_matches,guy>
try this test case
[[2,3],[1,3],[5,4],[7,4]]


*/