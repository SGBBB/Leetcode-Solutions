[https://leetcode.com/problems/reverse-linked-list-ii/discuss/30668/C%2B%2B-simple](http://)
​
​
​
```
class Solution {
//return type of reverse function is vector<ListNode* > of size 2 where the guy at 0th index is the head and guy at the 1st index is the guy next to head when only  1 node is left.
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
ListNode *pre=new ListNode(-1), *cur;
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
```