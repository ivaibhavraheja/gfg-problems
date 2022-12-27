long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long area=0;
    int s=0, e=len-1;
    while(s<e){
        int base = e-s;
        long long height = min(A[s], A[e]);
        long long a = base*height;
        if(a > area){
            area = a;
        }
        if(A[s]<A[e]){
            s++;
        }
        else{
           e--;
        }
    }
    return area;
}
