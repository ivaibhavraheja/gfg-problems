class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        int i=0;
        int j=n-1;
        //take all the smaller numbers in first array and bigger numbers in second array
        while(i < n && j > -1 && ar1[j] > ar2[i]){
            swap(ar1[j--], ar2[i++]);
        }
        //sort the reorganized arrays
        sort(ar1, ar1+n);
        sort(ar2, ar2+n);
        return ar1[n-1] + ar2[0];
    }
};
