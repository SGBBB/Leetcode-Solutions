class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end() );
        queue<string> q;
        q.push(beginWord);
        int changes=1;
        for(;!q.empty();changes++){
            int len=q.size();
            for(;len--;){
                string top=q.front();
                q.pop();
                if(top==endWord) return changes;
                
                
            for(char &ch:top){
                char temp=ch;
                for(char c='a';c<='z';c++ ){
                    //Im finding a word inside my hashmap which if differ by 1 character
                    ch=c;
                    if(s.count(top)) {
                        q.push(top);
                        s.erase(top);
        //while processing visited mark krne se sahi h ki usko delete krlo
                    }
                }
                ch=temp;
            }  
                
            }
            
        }
        return 0;
    }
    
    
};



/*

beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
intuition : you need to find another word differing by just 1 character

if you found such word push it into queue data strucutre

hit ----> hot ---> dot ---->dog ----->cog
        |                 |
        |                 |
        v                 v
       lot                log
*/






