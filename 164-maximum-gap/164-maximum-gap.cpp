class Solution {
public:
    int maximumGap(vector<int>& A) {
        int n=A.size();
    int min_guy=INT_MAX,max_guy=-1;
    for(int i:A)//loop to find max and min guys
        min_guy=min(min_guy,i),
        max_guy=max(max_guy,i);
        
    vector< pair<int,int> > store_gaps(n,{INT_MAX,INT_MIN});
    //every guy must lie under min_guyand max_guy
    if(min_guy==max_guy)  return 0;//since all guys are equal then difference will be 0 only 
    double gap= ( ((max_guy-min_guy )*1.0) / (n-1) );
        // gap=ceil(gap);
        // cout<<gap<<endl;
    for(int num:A){
        // cout<<gap<<endl;
        int pos=(num-min_guy)/gap;
        
        store_gaps[pos].first=min(store_gaps[pos].first,num),
        store_gaps[pos].second=max(store_gaps[pos].second,num);
    }
    //lets finally collect max_gaps
    int max_gap=gap,prev=store_gaps[0].second;
    for(auto  it:store_gaps){
        if(it.first==INT_MAX)continue;
        max_gap=max(max_gap,it.first-prev),
        prev=it.second;//updating prev every time;
    }
    
    return max_gap;
    }
};