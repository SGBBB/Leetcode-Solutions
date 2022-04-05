class Solution {
    double  f(vector<int>& A, vector<int>& B ){
        if(A.size()> B.size()) return f(B,A);
        //now A is smallest array 
        int n1=A.size() , n2=B.size() ;
        int l=0,h=n1;
        
        while(l<=h){
            int c1=(l+h)/2,
                c2=(n1+n2+1)/2-c1;
            cout<< c1<<" "<<c2 <<endl;
            int l1=(c1==0)?INT_MIN:A[c1-1],
                l2=(c2==0)?INT_MIN:B[c2-1],
                r1=(c1==n1)?INT_MAX :A[c1] ,
                r2=(c2==n2)?INT_MAX:B[c2];
            if(l1<=r2 &&   l2<=r1){
                if((n1+n2) & 1) //n1 +n2 is odd 
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            //update our search space
            if(l1>r2){
                //go left
                
                h=c1-1;
            }
            if(l2>r1){
                //go right 
                l=c1+1;
            }
        }
        return 0;
    }
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n1=A.size(),n2=B.size();
        if(n1==0){
            if(n2 & 1) return B[n2/2];
            else //n2 is even
                return (B[(n2-1)/2]+ B[n2/2])/2.0;
        }
        if(n2==0 ){//now we can process on n1
            if(n1 & 1) return A[n1/2];
            else //n1 is even
                return (A[(n1-1)/2]+A[n1/2])/2.0;
            
        }
        //now both of the Arrays have size.
        return f(A,B ); 
    }
        
};
/*
    [],[1,2,3,4]
*/