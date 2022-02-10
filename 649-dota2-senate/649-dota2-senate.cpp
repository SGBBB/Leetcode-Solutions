class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> Rad,Dir;
        int idx=0;
        for(char ch:senate) (ch=='R')?Rad.push(idx++):Dir.push(idx++);
        int n1=Rad.size(),n2=Dir.size();
        
        for(int len=idx;true;){
            if(Rad.empty()){return "Dire";}
            if(Dir.empty()){return "Radiant";}
            int rad_idx=Rad.front() ,dir_idx=Dir.front();                                 Rad.pop();Dir.pop();
            cout<<rad_idx<<" "<<dir_idx<<endl;
            if(rad_idx<dir_idx )  Rad.push(rad_idx+len);
            else Dir.push(dir_idx+len);
            
        }
        
        n1=Rad.size(),n2=Dir.size();
        cout<<n1<<" "<<idx<<endl;
        return n1>0?"Radiant":"Dire";
    }
};