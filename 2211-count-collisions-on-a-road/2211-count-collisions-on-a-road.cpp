class Solution {
public:
    int countCollisions(string directions) {
        //bc konsa ds use kru?? 
        /*an important thing R can be chopped by L but vica versa is nt gonna happen 
        
        
        should i use stack to cater this problme 
        
        
        
        */
        
        int  cnt=0;
        stack<char> st;
        for(char &ch:directions){ 
            // if(st.empty() ) {
            //     st.push(ch);
            //     continue;
            // }
            //conditions
            // if(!st.empty()){
            //     bool a=(st.top()=='R' && ch=='L'),
            //     b= 
            // }
            // while(!st.empty() && 
            //       ( (st.top()=='R' && ch=='L') || ( st.top()=='S' && ch=='L' ) ||( st.top()=='R' && ch=='S' ) )
            //      ){
            //     if(st.top()=='R' && ch=='L') cnt+=2;
            //     else if( ( st.top()=='S' && ch=='L' ) ||( st.top()=='R' && ch=='S' ))                           cnt+=1;
            //     st.pop();
            // } 
            // st.push(ch);
            
//             if(!st.empty() && ch=='L'){
//                 if( st.top()=='R' ) cnt+=2,st.pop(),st.push('S');
//                 else if(st.top()=='S' ) cnt++,st.pop(),st.push('S');
//                 else st.push(ch);
//             }
//             // else if(!st.empty() && ch=='R'){
//             //     // if(st.)
//             // }
            
//             else if(!st.empty() && ch=='S') { 
//                 if(st.top()=='R') cnt++,st.pop(),st.push('S');
//                 else st.push(ch);
//             }
//             else st.push(ch);//if ch 'R' ho ya  stack empty ho toh sidha push kro
            
                if(st.size( ) and ch=='L' &&  st.top()=='R') 
                     cnt+=2, st.pop() ,ch='S' ;
                else if(st.size( ) and  ch=='L' && st.top()=='S')
                     cnt+=1, st.pop() ,ch='S' ; 
            
            
            
            // cout<< cnt<<" st size is "<<st.top() <<st.size()<<" "<<ch<<endl;
            while(!st.empty() and ch=='S' && st.top()=='R')
            {cnt++,st.pop();}
            st.push(ch); 
            
        }
        return cnt;
    }
};