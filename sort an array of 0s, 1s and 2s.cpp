class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            // Logic for taking "0" at Starting position..
            if(a[mid] == 0){
                swap(a[mid], a[low]);
                low++;
                mid++;
            }
            
            // Logic for taking "2" at Ending position..
            else if(a[mid] == 2){
                swap(a[mid], a[high]);
                high--;
            }
            
            // Logic for taking "1" at between "0 and 2"..
            else if(a[mid] == 1){
                mid++;
            }
        }
    }
    
};
