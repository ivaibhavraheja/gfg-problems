class Solution
{
    public:
    int solve(int arr[], int n){
        int next1 = 0;
        int next2 = 0;
        int curr;
        
        for(int i=n-1; i>=0; i--){
            int incl = arr[i] + next2;
            int excl = 0 + next1;
            curr = max(incl, excl);
            
            //update after each iteration
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int ans = solve(arr, n);
        return ans;
    }
};
