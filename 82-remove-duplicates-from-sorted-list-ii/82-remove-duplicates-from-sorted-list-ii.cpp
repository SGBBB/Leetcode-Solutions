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
        ListNode *p,*prev;
        p=prev=new ListNode(-1);
        while(head){
            ListNode* cur=head;
            //use Line Sweep algo  that means we arent taking anyone among duplicate guys
            int cnt=0;
            while(cur && cur->val==head->val)
                cur=cur->next,cnt++;
            if(cnt>1) {
                prev->next=cur;
                head=cur;
            }
            else{ //this block is executed when my  cnt==1
                 prev->next=head,
                 prev=prev->next,
                 head=head->next;
            }
            
        }
        return p->next;
        
    }
};