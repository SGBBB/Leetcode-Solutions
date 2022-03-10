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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode* > s1,s2;
        for(;l1; l1=l1->next) s1.push(l1); 
        for(;l2; l2=l2->next) s2.push(l2); 
        int carry=0;
        ListNode* dummyHead=new ListNode(-11);
        while( !s1.empty() or !s2.empty()  or carry>0) {
            ListNode* nextNode=dummyHead->next;
            carry+=(!s1.empty()) ? s1.top()->val : 0 ;
            carry+=(!s2.empty()) ? s2.top()->val : 0 ;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            cout<<"carry is "<<carry<<endl;
            dummyHead->next=new ListNode(carry%10);
            carry /=10,
            dummyHead->next->next=nextNode;
        }
        return dummyHead->next;
    }
};