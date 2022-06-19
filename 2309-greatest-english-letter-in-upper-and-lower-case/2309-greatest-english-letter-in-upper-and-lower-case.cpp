class Solution {
public:
    string greatestLetter(string s) {
        // cout<<(char)('e'-32 ) <<endl;
        int arr[26][2]={}; //{sequence of alphabets}{ capital Leter,smallCase Leter}
         
        char potentialAns=' ';
        for(auto &ch:s){
            if( isupper(ch) ){
                arr[ tolower(ch)-'a' ][0]=1;
            }
            else{
                arr[ch-'a'][1]=1;
            }
            ch=tolower(ch);
            if( arr[ch-'a'][0]+arr[ch-'a'][1]==2  ){
                ch=toupper(ch);     
                cout<<ch<< " "<< (to_string(ch))<<" " <<( potentialAns)<<endl;
                if(   (ch)>potentialAns )
                    potentialAns=ch;
            }
        }
        string res=string(1,potentialAns);
        return   res==" "? "":res ;
    }
};