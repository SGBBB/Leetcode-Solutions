class Solution {
//     vector<int> computeExpression(string &expression,int i,int j){
//         for(int k=i+1;k<j;k+=2){
            
//             if( expression[k]=='-' ){
                
//             }
//             computeExpression()
//         }
//     }
public:
    vector<int> diffWaysToCompute(string expression) {
        // return computeExpression(expression,0,expression.size()-1);
        int n=expression.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            char ch=expression[i];
            if(!isdigit(ch)){ //At this moment my ch is surely an operator
                vector<int> Left=diffWaysToCompute(expression.substr(0,i));
                vector<int> Right=diffWaysToCompute(expression.substr(i+1));
                
                for(auto i:Left){
                    for(auto j:Right){
                        if (ch=='+')
                            ans.push_back(i+j);
                        else if (ch=='-')
                            ans.push_back(i-j);
                        else 
                            ans.push_back(i*j);
                    }
                        
                }
                
            }
        }
        if ( !ans.empty() )  return  ans;
        ans.push_back(stoi(expression));
        return ans;
    }
};