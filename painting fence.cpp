class Solution{
    public:
    long mod=1000000007;
    long long solve(int n,int k)
    {
        long same =k*1;
        long diff=(k*(k-1))%mod;
        long total=same+diff;
        if(n==1)
            return same;
        if(n==2)
            return diff;
        for(int i=3;i<=n;i++)
        {
            same=diff%mod;
            diff=(total*(k-1))%mod;
            total=same +diff;
        }
        return total%mod;
    }
    
    long long countWays(int n, int k){
        return solve(n,k)%1000000007;
    }
};
