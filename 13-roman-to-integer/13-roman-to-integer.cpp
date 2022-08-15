class Solution {
public:
    int romanToInt(string s) {
        // if some char is C/I/X then check for consecutive char also
        int digit=0,n=s.size();
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int i=0;
        while(i<n ){
            // checking for 6 special  cases
            int flag=0;
            if( s[i]=='I' ){
                if(i+1<n && s[i+1]=='X' ){
                    digit+=9,flag++;
                }
                else if(i+1<n && s[i+1]=='V'){
                    digit+=4,flag++;
                }
                    
            }
            else if(s[i]=='X' ){
                if(i+1<n && s[i+1]=='L' ){
                    digit+=40,flag++;
                }
                else if(i+1<n && s[i+1]=='C'){
                    digit+=90,flag++;
                }
            }
            else if(s[i]=='C'){
                if(i+1<n && s[i+1]=='D' ){
                    digit+=400,flag++;
                }
                else if(i+1<n && s[i+1]=='M'){
                    digit+=900,flag++;
                }
            }
            //if char itself can satisfy then increment by 1
            if(!flag){
                digit+=T[s[i]];
                i++; 
            }
            //if we wen tthrough special cases then increment by 2
            else  
                i+=2;
            
        }
        return digit;
    }
};