class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        /*
        
        1 3 5
        2 4 7
        
        
        1           4 5 9
        1           2 3 6
        
        2 2 6 6
        1 2 3 6
        
        */
        
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        
        int minMove=0,n=seats.size();
        for(int i=0;i<n;i++)
            minMove+=abs(seats[i] - students[i]);
        return minMove;
    }
};