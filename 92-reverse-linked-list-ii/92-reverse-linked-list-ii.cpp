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
/*Lets not do this using recursioin instead lets use some other technique*/


class Solution {
   
    vector<ListNode*>  reverse(ListNode * head, int left,int right){
        vector<ListNode*> ans(2);
        if(left<right){
            vector<ListNode*> res=reverse(head->next,left+1,right);
            head->next->next=head;
            head->next=NULL,
            
            ans[0]= res[0],
            ans[1]= res[1];
        }
        if(left==right) ans[0]=head,ans[1]=head->next;
        return ans;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(left<right){
        //     if(pos<left)
        //         // head=head->next;
        //         reverseBetween(head->next,left,right,pos+1);
        //     ListNode *newNode= reverseBetween(head->next,left+1,right);
        //     head->next->next=head,
        //     head->next=NULL,
        //     return newHead;
        // }
        // if(left==right) tailNode=head->next;
        // return head;
        ListNode *pre=new ListNode(INT_MIN), *cur;
        pre->next=head,
        cur=pre;
        int pos=0;
        
        for(;pos+1<left;pos++){
            cur=cur->next;
        }
        ListNode* tail=cur->next;
        vector<ListNode*> res=reverse(cur->next,left,right);
        cur->next=res[0],
        tail->next=res[1];
        
        return pre->next;
    }
};