class Solution {
public:
    int maxProduct(vector<string>& words) {
        /*
        
        ->maximum length of 2 words can be 26 atmost
        ["abcw","baz","foo","bar","xtfn","abcdef"]
        
        */
        int n=words.size();
        vector<int> bits_store(n);
        for(int i=0;i<n;i++){
            for(char it:words[i]){
                int pos=1<<(it-'a');
                bits_store[i]|=pos;
            }
            cout<<bits_store[i]<<endl;
        }
        int maxProduct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( !(bits_store[i] &bits_store[j]) )
                    maxProduct=max({maxProduct,(int)(words[i].size()*words[j].size())});
            }
        }
        return maxProduct;
    }
};