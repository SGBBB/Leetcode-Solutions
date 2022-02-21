# Actually intuition ye hai ki. koi bhi element ki frequency majority element  se jyada ni ho skte
1. thats why ap  repeatedly cancel krre ho elmeents ko n finally apko majority guy mil hi jaega
​
​
another approach using bitmasks :
```
int majority = 0;
for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
int bits = 0;
for (int num : nums) {
if (num & mask) {
bits++;
}
}
if(i<4)cout<< "bits cnt is "<<bits<<endl;
if (bits > nums.size() / 2) {
majority |= mask;
cout<< "majority cnt is "<<majority<<endl;
}
}
return majority;
```