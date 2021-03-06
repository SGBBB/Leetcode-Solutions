class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        long long hash = 0, res = 0, power_k = 1;
    
        long long i = s.size() - 1,j=i,K=k;
    for(;K--;i--){
        hash = (hash * power +(s[i]-'a'+1)) % mod;
        power_k = power_k * power % mod;
        if (hash == hashValue)
            { res=i;cout<<"hash is " << endl;   }
    }
    
    
    for (; i >= 0; --i,--j) {
        hash = (hash * power + (s[i]-'a'+1)*1) % mod;
        hash = (mod + hash - (power_k * (s[j]-'a'+1) ) % mod) % mod;
        
        cout<<"hash is " <<hash<<endl;    
        if (hash == hashValue)
            res=i;       
    }
    return s.substr(res, k);
    }
};