class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            /*
            "stack.size()  + A.size() - i > k" this line is checking whether we have enough eelements to sustain which i sgreater than k.
            
            */
            while (!stack.empty() && stack.back() > A[i] && stack.size()  + A.size() - i > k) 
                stack.pop_back();
            if (stack.size() < k)
                stack.push_back(A[i]);
        }
        return stack;
    }
};