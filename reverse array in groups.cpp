class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        int i=0, j=k;
        while(j<=n){
            //reverse the array from i to j with a group size of k
            reverse(arr.begin()+i, arr.begin()+j);
            i = j;
            j = j+k;
        }
        //reverse the remaining elements at the end
        if(i < n){
            reverse(arr.begin()+i, arr.end());
        }
    }
};
