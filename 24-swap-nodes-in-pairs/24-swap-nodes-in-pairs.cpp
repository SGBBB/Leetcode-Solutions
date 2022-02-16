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
    ListNode* helper(ListNode* node,int k=2){
        if(node)
        {
            ListNode* temp;
            if(!node->next) return node; //this means only one node is presnet
            for(temp=node;k--; temp=temp->next){ }
            //reverese the Linked List now
            k=2;
            ListNode* prev=NULL,*curr=node,*next;
            while(k--){
                next=curr->next, curr->next=prev, prev=curr,curr=next ;
            }
            
            ListNode* res=helper(temp);
            node->next=res;
            return prev;
            
        }
        return node;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return  head;
        return helper(head);
    }
};