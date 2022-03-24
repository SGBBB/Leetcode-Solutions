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
// bool compare(ListNode* a,ListNode* b){
//     return a->val>b->val;
// }
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode* > ,compare> pq;
        ListNode* dummyNode=new ListNode(-1),*tail=dummyNode;
        if(lists.empty()) return NULL;
        for(auto i:lists){
            if(i)
                {cout<<i->val<<" ";pq.push(i);} /*Here im just inserting head of every list to min heap*/
        }
        for(;!pq.empty();){
            ListNode* temp=pq.top();
            pq.pop();
            tail->next=temp;
            tail=temp;
            if(temp->next) pq.push(temp->next);
            
        }
        return dummyNode->next;
        
    }
};