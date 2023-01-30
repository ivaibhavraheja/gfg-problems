class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1;
        int s = 1;
        int e = n-2;
        long long int sum1 = a[0];
        long long int sum2 = a[n-1];
        while(s <= e){
            if(sum1 == sum2 && s == e)
                return s + 1;
            else if(sum2 < sum1){
                sum2 = sum2 + a[e];
                e--;
            }
            else{
                sum1 = sum1 + a[s];
                s++;
            }
        }
        return -1;
    }

};
