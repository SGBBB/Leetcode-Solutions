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
    ListNode* insertionSortList(ListNode* head) {
        if(!head->next) return head;  //if I m having only 1 node then return it
        
        ListNode *dummyNode=new ListNode(INT_MIN),*temp=head;
        dummyNode->next=new ListNode(temp->val);
        temp=temp->next;
        ListNode *curr=dummyNode->next,*prev=dummyNode;
        cout<<"bachodi "<<(curr->val)<<(temp->val)<<endl;
        for(;temp;temp=temp->next){
            if(temp->val>=curr->val) 
                curr->next=new ListNode(temp->val),curr=curr->next;
            else{
                //iska matlab khi beech mei insert krege ham
                for(;prev->next and !(prev->val<=temp->val and prev->next->val>=temp->val);)
                    prev=prev->next;
                ListNode *holder=prev->next;
                prev->next=new ListNode(temp->val),
                prev=prev->next,
                prev->next=holder;
                
                prev=dummyNode;
            }
             
        }
        
        return dummyNode->next;
    }
};