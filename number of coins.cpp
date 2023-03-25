class Solution{
    private:
    int solve(int coins[], int M, int V){
        if(V == 0){
            return 0;
        }
        if(V < 0){
            return INT_MAX;
        }
        
        int mini = INT_MAX;
        for(int i=0; i<M; i++){
            int ans = solve(coins, M, V-coins[i]);
            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }
        }
        return mini;
    }
    
    int solveMem(int coins[], int M, int V, vector<int> &dp){
        if(V == 0){
            return 0;
        }
        if(V < 0){
            return INT_MAX;
        }
        if(dp[V] != -1){
            return dp[V];
        }
        
        int mini = INT_MAX;
        for(int i=0; i<M; i++){
            int ans = solveMem(coins, M, V-coins[i], dp);
            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }
        }
        return dp[V] = mini;
    }
    
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> dp(V+1, -1);
	    int ans = solveMem(coins, M, V, dp);
	    if(ans == INT_MAX){
	        return -1;
	    }
	    return ans;
	} 
	  
};
