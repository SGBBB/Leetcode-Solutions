class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q ;
        int n=students.size();
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int rotations=0,i=0;//we are maintaining rotations becoz a guy who doesnt like a specific sandwich can pop and push many times so to monitor this that how many moves have been taken we are using rotations . if rotations went greater than q.size() that means we have a guy who is repeatedly popping and pushing every time and thus resulting in infinite moves. and if any guy has eaten sandwich we reset it as from now we can start new cycle.
        
        while(q.size() and  rotations<q.size()  ){
                if( q.front()==sandwiches[i]) {
                    rotations=0;                    
                    q.pop();
                    i++;
                    
                }
                else{
                    rotations++;
                    int choice=q.front();
                    q.push(choice);
                    q.pop();
                }
        }
        
        return q.size();
    }
};