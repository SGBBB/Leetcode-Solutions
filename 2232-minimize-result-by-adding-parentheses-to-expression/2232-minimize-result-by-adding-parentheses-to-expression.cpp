class Solution {
    int evaluate(string s){
        int res=0,left_val=INT_MAX,mid_val=0,right_val=INT_MAX ,i=0,n=s.size();
        for(;s[i]!='(';i++){
            if(left_val==INT_MAX) left_val=0;
            char ch=s[i];
            left_val=left_val*10+ch-'0';
        }
        i++;
        int mid_left=0,mid_right=0;
        for(;s[i]!='+';i++){
            char ch=s[i];
            mid_left=mid_left*10+ch-'0';
        }
        i++;
        for(;s[i]!=')';i++){
            
            char ch=s[i];
            mid_right=mid_right*10+ch-'0';
        }
        mid_val=mid_left+mid_right;
        i++;
        
        for(;i<n;i++){
            if(right_val==INT_MAX) right_val=0;
            
            char ch=s[i];
            right_val=right_val*10+ch-'0';
            
        }
        // if( s=="(247+3)8" )
        //         cout<<" insdie " <<  right_val <<" ====  ";
        if(left_val==INT_MAX) left_val=1;
        if(right_val==INT_MAX) {
            right_val=1;
            
        }
        res=left_val*mid_val*right_val;
        // if(s=="(247+3)8")
            cout<<s <<" " <<left_val<<" "<<mid_val  <<" "<<right_val <<endl;
        return res;
    }
public:
    string minimizeResult(string expression) {
        int idx=0,min_value=INT_MAX ;
        string ans;
        for(char ch:expression){
            if(ch=='+') break;
            idx++;
        }
        int pivot=idx;
        for(int i=0;i<pivot ;i++){
            string part1=expression.substr(0,pivot),
            part2=expression.substr(pivot+1);
            part1.insert(part1.begin()+i,'(');
            for(int j=1,n2=part2.size();j<n2+1;j++){
                part2.insert( part2.begin() + j ,')' );
                // cout<<(part1+'+'+part2)<<endl;
                int res=evaluate(part1+'+'+part2);
                if(res<min_value){
                    min_value=res;
                    ans=part1+'+'+part2;
                }
                part2.erase( part2.begin() + j   );
            }
        }
        return ans;
    }
};
/*
(247+3)8
intuition : for every  placing of braces on left side we are checking for all pairs on right side.
*/
// 1998