class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            int start = 0;
            int first_negative = -1;
            int count_negative = 0;
            int ans = 0;
            for(int i=0; i<n; i++){
                if(arr[i] == 0){
                    start = i+1;
                    first_negative = -1;
                    count_negative = 0;
                    continue;
                }
                if(arr[i] < 0){
                    count_negative++;
                    if(first_negative == -1){
                        first_negative = i;
                    }
                }
                if(count_negative % 2 == 0){
                    ans = max(ans, i-start+1);
                }
                else{
                    ans = max(ans, i-first_negative);
                }
            }
            return ans;
        }
};len
