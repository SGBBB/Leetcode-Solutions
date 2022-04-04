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
    ListNode* swapNodes(ListNode* head, int k) {
        /*
        initially let first pointer move k steps 
        if cnt>k then its time to move second pointer who is lagging by k steps.
        
        */
        ListNode* first,*second,*cur;
        first=second=cur=head;
        
        for(int cnt=1;cur;cnt++,cur=cur->next){
            if(cnt<k) first= first->next;
            if(cnt>k) second= second->next;
            
            
        }
        cout<<first->val<<" "<<second->val<<endl;
        swap(first->val,second->val);
        return head;
        
    }
};
/*
Is it possible to do it in single traversal??????


*/