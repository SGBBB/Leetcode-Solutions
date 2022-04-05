for(int i=0;i<n;i++)
{
if(degrees[i]==1)//adding all the leave nodes
queue.push(i);
}
while(!queue.empty())
{
res.clear();// clear vector before we start traversing level by level.
int size=queue.size();
for(int i=0;i<size;i++)
{
int cur=queue.front();
queue.pop();
res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
// if(cur==4) {
//     cout<<"cur is 4 "<< adj[cur].size() <<endl;
// }
for(auto &neighbor:adj[cur])
{
degrees[neighbor]--;//removing current leave nodes
if(degrees[neighbor]==1)//adding current leave nodes
queue.push(neighbor);
}
}
}
return res;
}
```
​