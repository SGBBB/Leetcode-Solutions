class Solution {
public:
    bool isRobotBounded(string instructions,int i=0,int j=0,char dir='N') {
        string direction_string="NWSE";
        vector< vector<int>  > direction_vector={{0,1} ,{-1 ,0 } ,
                                                 {0,-1} ,{1,0 }
                                                };
        
        for(char ch:instructions){
            int position=direction_string.find(dir);
            int x=direction_vector[position][0];
            int y=direction_vector[position][1];
           if(ch=='G' ) {
               
               i+=x;
               j+=y;
               
               
            }
            else if(ch=='L'){
                dir=direction_string[(position+1)%4];
                
            }
            else {
                
                dir=direction_string[(position+3)%4];
            }
            
            
        }
        cout<<"dire is "<<dir<<endl;
        bool ans1,ans2;
        // if( ) return ans1=1;
        cout<<!max(i,j)<<"   "<<i<<j<<endl;
         return (  !i and !j)or dir!='N';
        
    }
};