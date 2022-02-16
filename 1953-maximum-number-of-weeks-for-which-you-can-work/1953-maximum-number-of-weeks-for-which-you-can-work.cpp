class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0,max_element=1;
        
        for(long long i:milestones) sum+=i,max_element=max(max_element,i);
        long long diff=sum-max_element;
        cout<<"max_eleemtn "<<diff<<endl; 
        if(max_element>(sum-max_element))
            //do something 
            return (2*diff)+1;
        return sum;
    }
};