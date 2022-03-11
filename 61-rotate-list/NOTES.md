while(tail->next)  // get the number of nodes in the list
{
tail = tail->next;
len++;
}
tail->next = head; // circle the link
​
if(k %= len)
{
for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
}
newH = tail->next;
tail->next = NULL;
return newH;
}
};
```
​
```
vector <int> ans;
int len=1;
ListNode *tail,*newHead;
tail=newHead=head;
while (head->next){
tail=tail->next;
len+=1;
}
tail->next=head;
if (k%=len){
for (auto i=0;i<len-k;i++)
tail=tail->next;
}
newHead=tail->next;
tail->next=NULL;
return newHead;
```