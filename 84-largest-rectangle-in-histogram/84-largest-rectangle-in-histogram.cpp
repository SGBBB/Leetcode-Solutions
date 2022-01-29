class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> Left(n),Right(n);
        Left.front()=0,Right.back()=n-1;
        vector<int> temp;
        for(int i=0;i<n;i++){ 
            //calculating min_right
            for(;!temp.empty() and heights[temp.back()]>heights[i];
                
                Right[temp.back() ]=i-1,temp.pop_back() ){ }
            temp.push_back(i);
            
        }
        // 0 0 0 0 0 0
        for(;temp.size();Right[temp.back()]=n-1,temp.pop_back() ){ }
        temp.clear();
        //calculating left minimum
        for(int i=n-1;i>-1;i--){
            for(;!temp.empty() and heights[temp.back()]>heights[i];Left[temp.back()]=i+1,temp.pop_back() ){}
            temp.push_back(i);
        }
        for(;temp.size(); Left[temp.back()]=0,temp.pop_back() ){ }
        int max_ans=INT_MIN;
        for(int i=0;i<n;i++){
            max_ans=max(max_ans,heights[i]*(Right[i]-Left[i]+1) );
        }
        return max_ans;
    }
};