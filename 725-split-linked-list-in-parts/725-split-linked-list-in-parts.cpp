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
    vector<ListNode*>partition_list(ListNode* head , int remaining, int part_size ,int k ) {
        vector<ListNode *> ans;ans.clear();
        
        if(k>0 ) {
            ListNode* dummyHead=new ListNode(-11) ,*curr=dummyHead ;
            int temp=part_size+(remaining>0);
            for(;temp-->0;){
                ListNode* newNode=head;
                head=head->next,
                newNode->next=NULL,
                curr->next=newNode ,
                curr=curr->next    
                    ;
            } 
            ans.push_back(dummyHead->next);
            vector<ListNode * > res=partition_list(head,remaining-1,part_size, k-1) ;
            ans.insert(ans.end(), res.begin() ,res.end());
        }
        return ans;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         /*first compute the size of the linked list 
         2.Determin the remainder  
        */
        // if(!head) return {};
        
        int len=0;
        for(ListNode* temp=head;temp;  len++,temp=temp->next){}
        int remaining=len%k,part_size=len/k;
        return partition_list( head,remaining, part_size ,k) ; 
    }
};