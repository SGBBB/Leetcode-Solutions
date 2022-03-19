// struct node{
//     int freq,pos,val;
//     node(int freq,int pos,int val){
//         this->freq=freq,
//         this->pos=pos,
//         this->val=val;
//     }
// };
class FreqStack {
    int pos;
    unordered_map<int,int > M;
    priority_queue<vector<int>  > pq; //it's a max_heap
public:
    FreqStack() {
        //should I use this or not ?
        // sz=0;
        pos=0;
    }
    
    void push(int val) {
        // node * obj=new node(++M[val] , ++pos ,val);
         pq.push({++M[val] , ++pos ,val} );
    }
    
    int pop() {
        auto top=pq.top();
        pq.pop();
        M[top[2]]--;
        return top[2] ;
    }
};
/*
Cautious!
Hey Bora!
Before writing code try to think of approppriate data structure that suits best for the requirement of the problem statement.

*/
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */