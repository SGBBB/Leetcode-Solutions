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
    //blackbox work to reverse linked list
    vector<ListNode*> reverseList(ListNode* node,int left, int right){
        vector<ListNode*> arr(2);
        if(left<right){
            vector<ListNode*> response=reverseList(node->next,left+1,right);
            node->next->next=node;
            node->next=NULL;
            arr[0]=response[0],arr[1]=response[1];
        }
        else if(left==right)
            arr[0]=node,arr[1]=node->next;
        return arr;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos=0;
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* curNode=dummyNode;
        while(pos+1<left)
            curNode=curNode->next,pos++;
        ListNode* nextNode=curNode->next;
        vector<ListNode*>response= reverseList(nextNode,left,right);
        curNode->next=response[0];
        //if List after newHead exists then 
        if(response[1]){
            nextNode->next=response[1];
        }
        return dummyNode->next;
    }
};