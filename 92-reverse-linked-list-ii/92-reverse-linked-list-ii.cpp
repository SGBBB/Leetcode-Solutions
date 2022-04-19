/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<ListNode*> reverse(ListNode * node,int left,int right){
    //If i  dont appply recursion then it can be achieved iteratively as well
    cout<<left<<right<<endl;
    ListNode* prevNode=NULL;
    while( left<right ){
        
        ListNode* nextNode=node->next;
        node->next=prevNode;
        prevNode=node;
        node=nextNode;
        left++;
    }
    cout<<"node val is  "<<node->val <<endl;
    bool nextNodeNull=0;
    if( node->next ){
        ListNode* nextNode=node->next;
        node->next=prevNode; 
        return {node,nextNode};
    }
        //Now node-.next is NULL
    
    node->next=prevNode; 
    return {node,NULL};
    
 }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode=new ListNode(-1), *prevNode;
        dummyNode->next=head;
        prevNode=dummyNode;
        
    int cnt=0; 
    while(cnt+1<left){
        cout<<prevNode->next->val <<endl;
        prevNode=prevNode->next;
        cnt++;
    }
    ListNode* nextNode=prevNode->next;
    vector<ListNode*> NodeArray=reverse(prevNode->next,left,right);
    prevNode->next=NodeArray[0],
    nextNode->next=NodeArray[1];
    return dummyNode->next;
    }
};