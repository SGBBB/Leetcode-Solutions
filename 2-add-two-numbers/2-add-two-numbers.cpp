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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry=0) {
        // cout<<l1->val<<" "<<l2->val<<endl;
        if(l1 or l2 or carry>0){ 
            carry+=l1 ? l1->val : 0 ;
            carry+=l2?  l2->val:0 ;  
            ListNode* temp=new ListNode(carry%10);
            temp->next= addTwoNumbers(l1?l1->next:NULL,l2?l2->next:NULL ,carry/10) ;
            return temp;
        }
        return NULL;
    }
};