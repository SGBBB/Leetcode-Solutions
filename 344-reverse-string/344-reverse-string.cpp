class Solution {
public:
//     void reverseString(vector<char>& s) {
//         if(s.size()>1){
//             char temp=s.back();
//             s.pop_back();
//             reverseString( s );
//             s.insert(s.begin()+0, temp);
//         }
        
//     }
    // void reverseStringHelper(vector<char> &s,int i ,int j){
    //     if(i< j){
    //         swap(s[i],s[j]);
    //         reverseStringHelper( s ,i+1,j-1);
    //     }
    // }
//     void reverseString(vector<char>& s) {
        
//         reverseStringHelper(s,0,s.size()-1);
//     }
    // vector<char>  reverseStringHelper(vector<char> &s){
    //     vector<char> ans;
    //     if(!s.empty() ){
    //         char ch=*s.begin();
    //         s.erase(s.begin());
    //         auto response=reverseStringHelper(s);
    //         response.push_back(ch);
    //         ans=response;
    //     }
    //     return ans;
    // }
    void reverseStringHelper1(vector<char> &s,int i,int j){
        int n=s.size();
        cout<<i<<" "<<j<<endl;
        if(i<( (n+1)>>1)){
            reverseStringHelper1(s,i+1,j-1);
            swap(s[i],s[j]);
        }
        
    }
    void reverseString(vector<char>& s) {
        int n=s.size()-1;
        int i=0;
        reverseStringHelper1(s,i,n );
        
    }
};