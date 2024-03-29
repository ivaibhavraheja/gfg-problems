int solve(vector<int> &val, vector<int> &wt, int index, int capacity){
    //base case
    if(index ==  val.size()){
        return 0;
    }
    if(capacity == 0){
        return 0;
    }
    int include = 0;
    if(capacity >= wt[index]){
        include = val[index] + solve(val, wt, index+1, capacity-wt[index]);
    }
    int exclude = 0 + solve(val, wt, index+1, capacity);

    return max(include, exclude);
}


int solveMem(vector<int> &val, vector<int> &wt, int index, int capacity, vector<vector<int>> &dp){
    //base case
    if(index ==  val.size()){
        return 0;
    }
    if(capacity == 0){
        return 0;
    }
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }
    int include = 0;
    if(capacity >= wt[index]){
        include = val[index] + solveMem(val, wt, index+1, capacity-wt[index], dp);
    }
    int exclude = 0 + solveMem(val, wt, index+1, capacity, dp);

    return dp[index][capacity] = max(include, exclude);
}

int solveTab(vector<int> val, vector<int> wt, int C, int n){
    vector<vector<int>> dp(n+1, vector<int> (C+1, 0));
    //base case already satisfied
    //range
    for(int index=n-1; index>=0; index--){
        for(int capacity=1; capacity<=C; capacity++){
            int include = 0;
            if(capacity >= wt[index]){
                include = val[index] + dp[index+1][capacity-wt[index]];
            }
            int exclude = 0 + dp[index+1][capacity];
            dp[index][capacity] = max(include, exclude);
        }    
    }
    return dp[0][C];
}
