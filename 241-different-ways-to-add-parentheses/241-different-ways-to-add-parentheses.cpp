class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> response;
        int n=expression.size();
        for(int i=0;i<n;i++){
            char ch= expression[i];
            if(!isdigit(ch)){
                //I need response from left and right subarrays
                vector<int> left_response=diffWaysToCompute(expression.substr(0, i-0) );
                vector<int> right_response=diffWaysToCompute(expression.substr(i+1));
                for(int i:left_response){
                    for(int j:right_response){
                        int result=(ch=='+')?  i+j:ch=='*' ? i*j: i-j ;
                        response.push_back(result);
                    }
                }
                
                
                
            }
        }
        
        return ( !response.empty() ) ? response  : vector<int>{stoi(expression) };
    }
};