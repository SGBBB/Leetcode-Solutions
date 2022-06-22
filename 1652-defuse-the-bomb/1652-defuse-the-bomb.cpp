class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sz=code.size() ;
        vector<int> arr(sz);
        // if k==0
        if( !k )
            return arr;
            bool is_k_negative=k<0;
            k=(k<0) ? k*(-1) : k;
            int sum=0 ,i=0,j=0 ;
            while(  j<k  ){
                sum+=code[j],
                
                j = (j+1) ;
            }
            k=is_k_negative?k:sz-1;
            arr[k ]=sum;
            k=(k+1) % sz;
            int cnt=0;
            while(cnt<sz){
                sum-=code[i],
                sum+=code[j];
                arr[ k ]= sum;
                
                
                //updating values
                i=(i+1) % sz,j=(j+1) % sz, cnt++,
                k=(k+1) % sz;
            }
            
            return arr;
        
         
        return arr;
         
    }
};