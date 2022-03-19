class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
//         int n=text.size();
//         // if(n<2) return 0; 
//         long cnt_0=0,cnt_1=0,cnt=0;
//         for(char ch:text){
//             cnt_0+=ch==pattern.front(),
//             cnt_1+=ch==pattern.back() ;
//         }
//         // text=pattern[0]+text+pattern[1];
//         if(cnt_0<cnt_1) text=pattern[0]+text;
//         else if(cnt_0>cnt_1)text=text+pattern[1];
//         else text=pattern[0]+text+pattern[1];
//         cout<<"text is "<<text<<endl;
//         for(char ch:text){
//             cnt_0+=(ch==pattern.front() );
//             if(ch==pattern[1]){
//                 cnt_1++,
//                 cnt+=(cnt_0 ) ;
                
//                 cout<< "kitni bar "<<cnt<<" "<<cnt_1<<endl;
                
//             }
//             else if (ch==pattern[0] and cnt_1>0)  {
//                 // cnt_0=cnt_1=0;cout<< "kitni bar " <<endl;
//             }
//         }
//         return cnt*1LL;
        
        if(pattern[1]==pattern[0]) {
            long long cnt0=1; //appending either pattern[1] , pattern[0] to begin of text 
            for(char ch:text) cnt0+=pattern[0]==ch;
            return  (cnt0*(cnt0-1))>>1;
        }
        //if we are adding to the begining of text then 
        long long cnt0=1,cnt1=0,res1=0,res2; /*cnt0 is 1 because we have already appended pattern[0] to begining*/
        for(char ch:text){
            cnt0+=(ch==pattern.front());
            if(ch==pattern.back() )
                res1+=cnt0,
                cnt1++; 
        }
        cnt0=0,cnt1=0,res2=0;
        text+=pattern[1];/*We have actually appended the pattern [1] to end of text */
        for(char ch:text){
            cnt0+=(ch==pattern.front());
            if(ch==pattern.back() )
                res2+=cnt0,
                cnt1++; 
        }
        
        
        
        return max(res1,res2); 
        
    }
};