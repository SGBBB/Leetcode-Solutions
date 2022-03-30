```
bool divisorGame(int n) {
//person who endup having 1 is fucked off because he cant choose anything as given 0<choice<n
//So if Alice endup having 1 so she will left with no choice hence willl lose
for(int choice=1;choice<n ;choice++){
if( !(n%choice) ) {
int response=divisorGame(n-choice);
if( !response )  //Alice is expecting false from BOB then only it will return true
return true;
}
}
return false;
}
```