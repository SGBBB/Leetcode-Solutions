while(!st.empty() && nums[i]<nums[st.top()]){
//I wanna choose extremely smaller left anomaly index
startIdx=min({startIdx,st.top()}),
st.pop();
}
st.push(i);
}
//if startIdx isnt changed then Im sure that array is arranged in ascending order
if(startIdx==n)
return 0;
// Making stack empty for next iteration
while(!st.empty())
st.pop();
for(int i=n-1;i>=0;i--){
while(!st.empty() && nums[i]>nums[st.top()]){
//I wanna choose extreme right index where anomaly occured
endIdx=max({endIdx,st.top()});
st.pop();
}
st.push(i);
}
//Finally returning lenght if its possible to find unsorted subarray
return endIdx-startIdx+1;
}
```