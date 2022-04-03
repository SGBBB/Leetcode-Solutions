class Solution {
public:
    int convertTime(string current, string correct) {
        /*
        best way to go about this to convert hrs to minuites
        */
        int current_time=stoi(current.substr(0,2))*60 +                                                stoi(current.substr(3)),
        
            correct_time=stoi(correct.substr(0,2))*60 +                                                stoi(correct.substr(3)),
            time_diff=correct_time-current_time;
        // cout<<correct_time<<current_time<<endl;
        int choice[]={60,15,5,1},cnt=0;
        for(int i=0;i<4 && time_diff>0;i++){
            if(time_diff<choice[i])  continue;
            // cout<<choce
            cnt+=time_diff/choice[i],time_diff%=choice[i];
            
        }
        return cnt;
    }
};
/*
150 
275
lag=125 /60 -> 5/5 -> 0  

*/