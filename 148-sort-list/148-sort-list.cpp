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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head; 
        //determining mid node
        ListNode *fast=head,*slow= head;
        for(;fast and fast->next;fast=fast->next->next , slow=slow->next     ){  }
        //slow is the middle guy 
        ListNode *temp=head,*list1=temp;
        while(!(temp->next==slow)) temp=temp->next;
        temp->next=NULL;
        ListNode *res1=sortList(list1);
        ListNode *res2=sortList(slow);
        cout<<res2->val<<endl;
        //merge the lists we received as response
        ListNode *l1=res1,*l2=res2,*ans=new ListNode(-1),*dummyNode=ans;
        for(;l1 and l2;){
            if(l1->val<l2->val)  ans->next=new ListNode(l1->val), ans=ans->next,l1=l1->next;
            else ans->next=new ListNode(l2->val), ans=ans->next ,l2=l2->next;
        }
        while(l1) ans->next=new ListNode(l1->val), ans=ans->next,l1=l1->next;
        while(l2) ans->next=new ListNode(l2->val), ans=ans->next ,l2=l2->next;
        //
        return dummyNode->next;
        
    }
};