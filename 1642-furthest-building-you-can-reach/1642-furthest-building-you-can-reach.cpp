class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //logic is initially we are using bricks  then if in need we will use ladders
        priority_queue<int> pq;
        int len=heights.size(),i=1;
        for(;i<len;i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                pq.push(diff);
            bricks-=diff;
            if(bricks<0){ //if bricks are 0 this means we have already used  bricks
                ladders--; //if im short of bricks then use ladders
                
                bricks+=pq.top(), pq.pop();
                if(ladders<0 or bricks<0) return i-1;
                
                
            }
            }
        }
        return len-1;
    }
};