struct Node{
    Node*  arr[2];//it will contain only 2 values 1 ,0
    int number;  
};
Node *root=new Node(); //defining root globally
class Solution {
    void insert(int key){
        Node* temp=root;
        for(int j=31;j>=0;j--){
            bool idx=(key & (1<<j))    ;      
            if(!temp->arr[idx]){
                temp->arr[idx]=new Node();
            }
            temp=temp->arr[idx];
        }
        temp->number=key;
    }
    
    int find_maximum_xor_pairs(int key){
        Node* temp=root;
        int j=31;
        
        for(;j>=0;j--){
            // Node* temp=root;
            bool idx=(key & (1<<j))    ;
            if( temp->arr[!idx] ){ 
                temp=temp->arr[!idx];
            }
            else if(temp->arr[idx]) { //go trail down with same bit
                temp=temp->arr[idx];
            }  
            // else return INT_MIN;
        }
        return (temp->number)^key;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        root=new Node();
        
        int maxXOR=INT_MIN;
        insert(nums[0]);
        int i=1,n=nums.size();
        if(n<2) return 0;
        for(;i<n;i++){
            //
            maxXOR=max( maxXOR,find_maximum_xor_pairs(nums[i])   );
            insert(nums[i]);
            
        }
        
        return maxXOR;
    }
};