bool cmp(vector<int> v1,vector<int> v2){
    return v1[1]<v2[1] ;
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        /*
        
        100  200
        200  1300
        1000 1250
        2000 3200
        
        
        
        3 2 
        4 3
        
        Seems like greedy algorith can be applied here
        Intution: 
        Initilally I;ll enroll a course with least completion time
        At the end I'll enroll a course with most completion time.
        
        [[1000,200],[1000,1250],[900,1250],[200,1300],[2000,3200]]
        
        
        */
        sort(courses.begin(),courses.end(),cmp);
        int elapsedTime=0;
        multiset<int> S;
        for(auto it:courses){
            elapsedTime+=it[0];
            S.insert(it[0]);
            if(elapsedTime>it[1]){
                int highestDurationUNtilNow= *(--S.end());
                S.erase(--S.end());
                elapsedTime-=highestDurationUNtilNow;
            }
                
        }
        return  S.size() ;
    }
};