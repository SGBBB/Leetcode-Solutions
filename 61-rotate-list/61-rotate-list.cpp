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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        //  ab mere list mei atleast 1 node hai
        int len=1;
        ListNode * temp=head;
        for(;temp->next;len++,temp=temp->next){}
            
        k%= len,
        temp->next=head ;//linked list ko circular kiya h 
        cout<<"len is "<<len<<endl;
        int cnt=len-k;
        ListNode * prev=NULL;
        for(;cnt-- ;){
            prev=head,head=head->next;
            
        }
        prev->next=NULL;
        return head;
    }
};