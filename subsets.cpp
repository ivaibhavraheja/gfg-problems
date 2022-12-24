class Solution
{
    void solve(vector<int> &A, vector<vector<int>> &ans, int index, vector<int> output){
        //base case
        if(index >= A.size()){
            //collect subsets
            ans.push_back(output);
            return;
        }
        
        //excluding the values
        solve(A, ans, index+1, output);
        
        //including the values;
        output.push_back(A[index]);
        solve(A, ans, index+1, output);
    }
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<int> output;
        vector<vector<int>> ans;
        int index = 0;
        solve(A, ans, index, output);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
