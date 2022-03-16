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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *r=new ListNode(0);
        ListNode *q=head;
        while(q)
        {
            ListNode *p =r;
            while(p->next!=NULL && p->next->val<q->val)
            {
                p=p->next;
            }
            ListNode *k=q->next;
            q->next=p->next;
            p->next=q;
            
            q=k;
        }
        return r->next;
    }
};