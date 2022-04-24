class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size() ,cnt=0;
        for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++){
                bool flag=0;
                for(int k=0;k<n;k++){
                    int x=circles[k][0] ,y=circles[k][1] ,radius=circles[k][2];
                    int dist=(i-x)*(i-x) + (j-y)*(j-y);
                    
                    if(dist<=(radius*radius) ){
                        flag=1;
                        break;
                    }
                    
                }
                 cnt+=flag==true;   
            }
                
        }
        
        
        return cnt;
        //time complexity is 200*200*circle.size()
    }
};