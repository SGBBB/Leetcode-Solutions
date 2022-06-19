class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        /*
        
        baggage 
        bags 
        banner
        box
        cloths 
        
        
        "bags",
        "zags"
        */
        
        int n= searchWord.size(), s=0,e= products.size()-1;
        for(int i=0;i<n;i++){
            char ch=searchWord[i];
            while(s<=e &&   products[s][i]!=ch )
                s++;
            while(e>=s &&  products[e][i]!=ch )
                e--;
            cout<< s<<" "<<e<<endl;
            vector<string> prefix_string_store;
            
            if(s>e) {
                 
            }
                
            int products_cnt=min(3,e-s+1);
           if(s>e) {
                 products_cnt=0;
            }
            for(int j=0;j<products_cnt ;j++){
                prefix_string_store.push_back(products[s+j]);
            }
            ans.push_back(prefix_string_store);
        }
        return ans;
    }
};


 