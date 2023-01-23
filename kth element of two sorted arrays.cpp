class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0; i<n; i++)
        {
            p.push(arr1[i]);
        }
        for(int i=0; i<m; i++) 
        {
            p.push(arr2[i]);
        }
        for(int i=1; i<=k; i++)
        {
            if(i==k)
            {
                return p.top();
            }
            else
            {
                p.pop();
            }
        }
    }
};
