class Solution{
public:
    int inSequence(int A, int B, int C){
        //b = a + (n-1)c
        //b-a = (n-1)c
        //n = (b-a)/c + 1;
        if(C == 0){
            if(A == B){
                return 1;
            }
            else{
                return 0;
            }
        }
        int n = ((B-A)/C) + 1;
        if(B == A+(n-1)*C && n>0){
            return 1;
        }
        else{
            return 0;
        }
    }
};
