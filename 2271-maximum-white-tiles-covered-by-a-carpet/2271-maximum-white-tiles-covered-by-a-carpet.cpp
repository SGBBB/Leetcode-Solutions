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
        int maximumWhiteTiles(vector<vector<int>>& t, int len) 
	{
	    int res = 0, j = 0, cover = 0;//cover is length of white tiles covered by carpet in current window
	    sort(t.begin(), t.end());
	    for (int i = 0; i < t.size();)//carpet starts from j and end at i
	    {
	        if (j == i || t[j][0] + len > t[i][1]) //carpet starting from j is exceeding this window(as this window is ending at i)
			{
	            cover += t[i][1] - t[i][0] + 1;//this window is being extended to cover this patch also
	            res = max(res, cover);
	            ++i;//let this window try to cover next patch by expanding its right end
	        }
	        else//carpet starting from jth patch is not able to cover this whole patch at i 
			{
	            res = max(res, cover + max(0, t[j][0] + len - t[i][0]));
	            					/* Partial length covered by 
	            					   carpet in this patch
	            					*/
	            cover -= (t[j][1] - t[j][0] + 1);//window will slide towards right hence remove the contribution of cover given by left most patch of current window. 
	            ++j;//slide the window towards its right
	        }
            cout<<cover << " "<< res<<endl;
	    }
	    // return min(res,len);
            return res;
    }
};