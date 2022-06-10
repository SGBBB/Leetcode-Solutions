class Solution {
public:
    int getMinSwaps(string num, int k) {
        /*
        
        5142
        5421
        
        11112
        
        21111
        
        11112 <-- Original String
        
        21111 <- Final Modified String
        
        
        
        
        
        00123
        00132
        00213
        00231
        00312
        
        
        00321
        01023
        01203
        01230
        01302
        01320
        
        
        
        
        0[0123 ->0[1320 (10)
        0[1320 ->0[1320 ->
        
        
        01320 -> 01320
        Observations:
        1. Interested to know until which idx did changes happened
        2. Now You know until which idx given string is changed lets start            from end and try to put every char to its original position.
        
        11112
        
        
        Madarchod sawal chutie ne gand todd di
        
        */
        
        string original = num;
        
        while(k--) {
            next_permutation(num.begin(), num.end());
        }
        int n=original.size() , minSteps=0,  i=0;
        for(;i<n;i++){
            //Whenever I met first change grab it
            if(num[i]!=original[i])
                break;
                
        }
        cout<<"i "<<i <<"  "<< num<<endl;
        //Now I'm aware about where changed has actually happened
        while(i < n ){
            int j=i;
            while( original[j]!=num[i] )
                j++;
            while(j>i){
                swap ( original[j],original[j-1] ) ,
                minSteps ++ ,
                j--;
                cout<< original<<endl;
            }
            
            
            // cout<< original<< " == "<<num <<endl;
            i++;
        }
        return minSteps;
    }
};