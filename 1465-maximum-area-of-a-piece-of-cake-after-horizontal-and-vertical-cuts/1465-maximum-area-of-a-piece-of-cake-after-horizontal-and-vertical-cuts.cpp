class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        using ll=long long;
        /*
        Try to sort the given cuts
        Intuition: Try to check area for every block
        
        
        */
        int h_sz=horizontalCuts.size(),
            v_sz=verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        ll prev_measure=0,maxHorizontalCut=0,maxVerticalCut=0;
        for(int i=0;i<h_sz;i++){
            maxHorizontalCut=max( {maxHorizontalCut,horizontalCuts[i]-prev_measure} );
            prev_measure=horizontalCuts[i];
            //If Im at the last guy then do sz - cur cut
            if(i==h_sz-1)
                maxHorizontalCut=max( {maxHorizontalCut,h-prev_measure} );
        }
        prev_measure=0;//reset prev_measure
        for(int i=0;i<v_sz;i++){
            maxVerticalCut=max( {maxVerticalCut,verticalCuts[i]-prev_measure} );
            prev_measure=verticalCuts[i];
            //If Im at the last guy then do sz - cur cut
            if(i==v_sz-1)
                maxVerticalCut=max( {maxVerticalCut,w-prev_measure} );
        }
        return 
            (long)(maxHorizontalCut*maxVerticalCut)%1000000007;
    }
};