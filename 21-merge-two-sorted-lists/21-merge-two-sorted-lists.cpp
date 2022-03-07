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
public://lets do it using recursion
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2) return list1;
        if(!list1 and  list2 ) return  list2;
        else if(list1 and  !list2 ) return list1;
        
        if(list1->val<list2->val){
             list1->next=mergeTwoLists(list1->next, list2);
            return list1;
        }
        // now it means that list2 is smaller value
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }
};