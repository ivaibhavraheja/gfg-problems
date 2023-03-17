class Solution
{
    static bool cmp(Item a, Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1 > r2;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0;
        int m = W;
        sort(arr, arr+n, cmp);
        for(int i=0; i<n; i++){
            if(arr[i].weight <= m){
                ans = ans + arr[i].value;
                m = m - arr[i].weight;
            }
            else{
                ans = ans + (double)m* ((double)arr[i].value / (double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
        
};
