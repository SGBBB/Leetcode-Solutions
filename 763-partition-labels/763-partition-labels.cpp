struct node{
    int first_occur=0,last_occur=0;
    char ch;
    node(char ch, int first_occur,int last_occur){
        this->ch=ch,
        this->first_occur=first_occur,
        this->last_occur= last_occur;
        
    }
};
bool cmp(vector<int> x,vector<int> y){
    if(x[0]!=y[0])
    return x[0 ] <y[0] ;
    return x[1]>y[1];
}
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector< int>> freq(26,vector<int> (2,-1))  ,freq1;
        vector<int> ans;
        // we will do this ans.push_back( length gained until now ) when we met a first  greater than prev
        int idx=0;
        for(char ch:s){
            if( freq[ch-'a'][0]==-1) freq [ch-'a'][0]=idx,freq[ch-'a'][1]=idx; //if you found guy for the first time then update both start and end values
            
            else freq[ch-'a'][1] =idx; //if you found guy earlier then just update its last value
            idx++;
        }
        
        for(vector<int>  i:freq){
            if(i[0]>-1 ) {
                freq1.push_back(i);
            }
        }
        //here i'll oerform sorting 
        sort(freq1.begin() ,freq1.end()  ,  cmp);
        int len=0, start=0,end=0;
        for(vector<int> i:freq1){
            if(i[0]>end) {
                ans.push_back(end-start+1);
                start=i[0] ,
                end= i[1] ;
                
            }
            else {
                end=max(end,i[1]);
            }
            
        }
        // for(auto i:freq1) 
        //     cout<<i[0] << " "<<i[1]<<endl;
        ans.push_back(end-start+1);
        
        
        
        
        return ans;
    }
};


/*

ababcbaca defegdehijhklij
a  0  8
b  1  5
c  4  7
//second partition starts from here
d  9  14
e 10  15
f 11  11
g 13  13
// last partition start from here
h 16  16




*/