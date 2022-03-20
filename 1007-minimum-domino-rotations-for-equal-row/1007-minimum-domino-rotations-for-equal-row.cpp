class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int visited[20001]={} ,freq[7]={} ,bigTop;
        int n=tops.size(),max_top=0;
        for(int i:tops)
            if(max_top<++freq[i])
                max_top=freq[i],bigTop=i;
        
        for(int i=0;i<n;i++)
            if(tops[i]==bigTop)
                visited[i]=1;
        int cnt1=0,cnt2=0;
        if(freq[bigTop]==n) return 0;//edge case
        for(int i=0;i<n;i++){
            if(!visited[i] and bottoms[i]==bigTop) cnt1++;
                
        }
        //when conditiions case got ripped
        if((cnt1+freq[bigTop])==n) cnt1=cnt1;
        else cnt1=-1;
        freq[1]=freq[2] =freq[3] = freq[4]= freq[5]= freq[6]=0;//reset freq. array
        for(int i=0;i<n;i++)
            visited[i]=0;
        bigTop=0,max_top=0;;//reset maxi
        //visiting bottom
        for(int i:bottoms) 
            if(max_top<++freq[i])
                max_top=freq[i],bigTop=i;
        
        for(int i=0;i<n;i++)
            if(bottoms[i]==bigTop)
                visited[i]=1;
        
        if(freq[bigTop]==n) return 0;//edge case
        for(int i=0;i<n;i++){
            if(!visited[i] and tops[i]==bigTop) cnt2++;
                
        }
        //When cnt2 + freq[bigTop] isnt == to n
        if((cnt2+freq[bigTop])==n) cnt2=cnt2;
        else cnt2=-1;
        
        cout<<cnt1<<" " <<cnt2<<endl;
        
        if(cnt1==-1 and cnt2>-1 ) return cnt2;
        else if(cnt1>-1 and cnt2==-1) return cnt1;
        else if(cnt1>-1 and cnt2>-1) return min(cnt1,cnt2);
       
        // return min(cnt1,cnt2);
        return -1;
    }
};