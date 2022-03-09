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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        int prev=-1001;
        ListNode* dummyHead=new ListNode(-11001) , *temp=dummyHead;
        for(ListNode* cur=head; cur  ;cur=cur->next){
            
            if( (prev!=cur->val )     ){
                if(  !cur->next   or  ( cur->next and cur->val!=cur->next->val)   )
                temp->next=new ListNode(cur->val) ,
                temp=temp->next ;
            }
            prev=cur->val;
        }
        return dummyHead->next;
    }
};
/*
1  2 3  3  4           //let this part go 4  5
     c  n    
     
1 1 
1 
     
*/