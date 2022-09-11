class Solution {
public:
    bool winnerOfGame(string colors) {
        int AliceMoves=0,BobMoves=0,i=0,n=colors.size();
        while(i<n){
            int curCnt=0;char curColor=colors[i];
            while(i<n && colors[i]==curColor){
                i++,curCnt++;
            }
            if(curColor=='A')
                AliceMoves+=max({0,curCnt-2});
            else
                BobMoves+=max({0,curCnt-2});
            if(curCnt==0)// if while loop didnt executed then update i
                i++;
        }
        //if Alice went out of moves,then Bob won
        if(!AliceMoves)
            return 0;
        //if Alice has got score then compare the scores
        else if(AliceMoves>0){
            if(AliceMoves>BobMoves)
                return 1;
            return 0;
        }
        return 0;
    }
};

/*

            a A a b b a a b B b
            & A ,*  B
            a a a a b b b b a
            a & & a b * * b a


            A B B B B B B B A A A 
            
            Alice will play n even no
            Bob will play in odd no
            
            while returning res I'll check whether Alice played or not
            1. If Alice didnt played asingle move then return 0; as she was out of moves.
            2. If Alice has got score,then both of their score will be compared The guy with more score will win
            
            
*/