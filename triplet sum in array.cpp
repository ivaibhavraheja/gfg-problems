class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //use this approach on sorted array
        sort(arr, arr+n);
        bool found = false;
        
        for(int i=0; i<n-1; i++){
            int l = i + 1;
            int r = n - 1;
            while(l<r){
                if(arr[i] + arr[l] + arr[r] == X){
                    found = true;
                    return found;
                }
                else if(arr[i] + arr[l] + arr[r] > X){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }

};
