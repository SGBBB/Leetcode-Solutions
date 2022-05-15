// cmp(vector<int> arr1,vector<int> arr2){
//     if(arr1[1]!=arr2[1])
//         return true;
    
//     return arr1[0]<arr2[0]
// }

class Solution {
    
    /*
    Approach to solve this problem:
    count lengths of various non overlapping segments 
    2.this can be achieved through via sorting these tiles in ascending order with respect to the right value corresponding to every tile
    Dont follow 2. step since tiles are non overlapping
    I can sense that this is a greedy problem
    intuition i cann sense: I think we wanna find max length of contiguous patch of tiles having total legnth <= carpetLen
    
    
    
    */
public:
        int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
            
    //Sort tiles by start index , this also gurantee that tiles will also sorted by end index due to non overlapping condition
    sort(tiles.begin(), tiles.end());
    int n = tiles.size();
    int cover=0,res=0;
        //here e is acting as the end of tile and s is acting as the start of tile
    for(int s=0,e=0 ;e<n ;  ){
        if( e==s || tiles[s][0]+len>tiles[e][1] ){
            cover+=tiles[e][1]-tiles[e][0]+1;
            res=max(res,cover);
            e++;
        }
        else{
            res=max(res,cover+ max(0, tiles[s][0]+len-tiles[e][0] ) );
            cover-=tiles[s][1]-tiles[s][0]+1;
            s++;
        }
    }
    return min(len,res);
        }
};