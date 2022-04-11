class Solution {
public:
    int largestInteger(int num) {
        if(num/10==0) return num;//if singnle digit is present then simply return it
//         vector<int> digit; 
//         priority_queue<vector<int> > pq;
//         while(num>0){
//             int temp=num%10;
//             digit.insert(digit.begin(),temp);
            
                
//             num/=10; 
            
//         }
//         int n=digit.size();
//         //I'll ensure that starting two position holds bigger possible guy
//         for(int idx=0;idx<n;idx++){
//             int temp=digit[idx];
//             pq.push({temp,idx}); 
//         }

//         /*
//         Just try brute force to cerack this problem
        
//         */
//         vector<int>visited(n);
//         int cnt=0;
//         while(!pq.empty() && cnt<2){
//             auto top=pq.top();
//             pq.pop();
//             bool isodd=top[0] &1;
//             if(isodd)
//             for(int i=0;i<n;i++){
//                 if( (digit[i]&1) && digit[i]<=top[0]){
//                     swap(digit[i],digit[top[1]]),cnt++;
//                 }
//             }
//             else{
//                 for(int i=0;i<n;i++){
//                     if( !(digit[i]&1) && digit[i]<=top[0]){
//                         swap(digit[i],digit[top[1]]),cnt++;
//                     }
//                 }
//             }
//         }
        
//          //afain forming number from digit array
//         for(int i:digit){
//             num=num*10 + i;
//         }
//         return num;
        string odd="",even="",digit=to_string(num);
        for(char ch:digit){
            int num=ch-'0';
            if(num & 1) odd+=ch;
            else even+=ch;
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());
        int i=0,j=0;
        for(char &ch:digit){
            int num=ch-'0';
            if(num & 1){
                ch=odd[i++];
            }
            else
                ch=even[j++];
        }
        return stoi(digit);
    }
};