class Solution {
public:
    vector<long long> sumOfThree(long long num) {
//         vector<long long> window(num/2,0),ans;
        // ;
        if(num%3) return {};
//          long long n=window.size(),idx=0;
//         cout<<"n i "<<n<<endl; 
//         for(auto &i:window){
//             i=idx++;
//         }
//         // for(auto i:window) cout<<i<<endl;
//         long long i=0,j=0,val=0;
        
//         for(;j<3;j++){
//             val+=window[j];
//         }
//         if(val==num) {
//             return {window[0],window[1],window[2] };
//         }
//         cout<<"vale is "<<val<<endl;
//         for(i=0,j=3;j<(n);i++,j++){
//             val-=window[i],val +=window[j]; 
//             if(val==num) {cout<<"true"<<endl; return {window[j-2], window[j-1],window[j]};}
//             cout<<"vale is "<<val<<endl;
//         }
//         return  {};
         long long mid_guy=num/3;
         return ( ( (mid_guy-1) +mid_guy+ mid_guy+1)==num ) ? vector<long long> {(mid_guy-1) ,mid_guy, mid_guy+1}: vector<long long>{} ;
    }
};