class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0; i<n-1; i++){
            maxi = max(maxi, arr[i]);
            sum = sum + arr[i];
        }
        
        //only 1 is present
        if(sum == 1){
            return 2;
        }
        //last digit is not present
        if(maxi != n){
            return n;
        }
        
        int actualSum = 0;
        for(int i=1; i<=maxi; i++){
            actualSum += i;
        }
        
        return actualSum - sum;
    }
};
