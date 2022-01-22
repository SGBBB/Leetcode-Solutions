class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string ,char > string_map;
        unordered_map<char ,string > pattern_map;
        stringstream ss1(s) , ss2(s);
        string str1;
        int len=pattern.size();
        int cnt=0;
        for(;ss2>>str1;cnt++) {}
        cout<<len<<" "<<cnt<<endl;
        if(len!=cnt) return 0;
        cout<<str1<<endl; 
        str1="";
        for(int i=0;ss1>>str1;i++){
            char ch=pattern[i];
        if(string_map.find(str1)==string_map.end() and pattern_map.find(ch)==pattern_map.end()  )
            string_map[str1]=ch,pattern_map[ch]=str1;
        else if ( !(string_map[str1]==ch and pattern_map[ch]==str1  )) return false;
        
    }
        return true;
    }
};