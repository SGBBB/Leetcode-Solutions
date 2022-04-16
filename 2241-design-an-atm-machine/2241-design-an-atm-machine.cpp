// struct node{
//     int twenty,fifty,hundred,twohundred,fivehundred;
//     node(vector<int > arr){
//         this->twenty=arr[0],
//         this->fifty=arr[1],
//         this->hundred=arr[2],
//         this->twohundred=arr[3],
//         this->fivehundred=arr[4];
//     }
// };
class ATM {
    long  val[5]={20,50,100,200,500};
    long  cnt[5]={0,0,0,0,0};
    
    // node currencyStore();
    
public:
    ATM() {
        
    }
    
    void deposit(vector<int> currency) {
        int idx=0;
        for(auto it:currency){
            cnt[idx++]+=it;
        }
        
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        for(int i=4;i>-1;i--){
            if(!amount) break;
            if(!cnt[i] || amount<val[i] ) continue;
            ans[i]=min( cnt[i],amount/val[i] );
            amount-=ans[i]*val[i];
        }
        if(amount>0 )  return{-1};
        for(int i=4;i>-1;i--) 
            cnt[i]-=ans[i];
        for(int i:cnt) cout<< i <<" ";cout<<"for val amount "<<amount<<endl;
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

/*
I think we can apply greedy algo to solve this.
*/