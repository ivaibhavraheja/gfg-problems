class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> res;
        if(n==0){
            return res;
        }
        long long ans = arr[0];
        for(int i=0, j=0; i<n && j<n;){
            if(ans == s){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(ans < s){
                j++;
                ans += arr[j];
            }
            else if(ans > s){
                ans -= arr[i];
                i++;
                if(i>j){
                    j++;
                    i=j;
                    ans += arr[i];
                }
            }
        }
        res.push_back(-1);
        return res;
    }
};
