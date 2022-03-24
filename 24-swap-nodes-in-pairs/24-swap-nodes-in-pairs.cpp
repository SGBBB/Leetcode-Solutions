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
    ListNode* helper(ListNode* node){        
        /*Main Logic */
        if(!node or !node->next){    //this line states that if I'm having one or no node so consider returning it        
            return node;            
        }
    ListNode* newHead=helper(node->next->next);
    // newHead ;
    ListNode * temp=node->next;
    node->next= newHead;
    temp->next=node;
    return temp;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        // if(!head) return head ;
        // return helper(head); 
        if(!head or !head->next) return head;
        // now i'm sure that there are nodes present in pairs
        ListNode* newHead=swapPairs(head->next->next);
        ListNode* temp=head->next;
        head->next=newHead;
        temp->next=head;
        
        return temp;
    }
};