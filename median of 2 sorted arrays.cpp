class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        if(array2.size() < array1.size()){
            return MedianOfArrays(array2, array1);
        }
        int n1= array1.size();
        int n2 = array2.size();
        int n = n1 + n2;
        int low = 0;
        int high = n1;
        
        while(low <= high){
            int cut1 = (low + high) >> 1;
            int cut2 = (n + 1)/2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : array1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : array2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX : array1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : array2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else{
                    return max(l1, l2);
                }
            }
            else if(l1 > r2){
                high = cut1- 1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};
