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
        ListNode *dummyNode=new ListNode(0);
        ListNode *q=head; // q is just giving the nodes to fit in sorted list.
        while(q)
        {
            ListNode *cur =dummyNode;
            /* the moment when p->next->val went smaller than q->val ,then do interchanging. */
            while(cur->next!=NULL && cur->next->val<q->val)
                cur=cur->next;
            ListNode *nextNode=q->next; //saving q->next
            q->next=cur->next; //  q ke right se connect krre h
            cur->next=q; //q ke left se connect krre h
            q=nextNode;    //updating q to its next value
        }
        return dummyNode->next;
    }
};