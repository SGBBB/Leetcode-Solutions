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
        ListNode* prev=new ListNode();
        ListNode* p=prev;
        while(head){
            ListNode* cur=head;
            int c=0;
            while(cur && cur->val==head->val){
                cur=cur->next;c++;
            }
            if(c>1){
                prev->next=cur;
                head=cur;
            }
            else {
                prev->next=head;
                    prev=head;
                head=head->next;
            }
            
        }
        return p->next;
    }
    
};