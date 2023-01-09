class Solution {
  public:
    int solve(int N, vector<int> A) {
        if(A[N-1] < 9)
            return N;
        int carry = 1;
        int i= N-1;
        while(carry != 0){
            i--;
            A[i] += carry;
            if(A[i] > 9)
                carry = 1;
            else
                carry = 0;
        }
        return i+1;
    }
};
