class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        string ans(n1+n2,'0');
        for(int i=n1-1;i>=0;i--){
            int carry=0;
            for(int j=n2-1;j>=0;j--){
                int temp=carry+(ans[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') ;
                ans[i+j+1]='0'+temp%10;
                carry=temp/10;
            }
            if(carry>0) 
                ans[i]+=carry ;
        }
        int pos=0;
        while(pos<(n1+n2) && ans[pos]=='0' ) 
            pos++;
        if(pos==n1+n2) return "0";
        return ans.substr(pos);
    }
};

/*
"123"
"6"
*/