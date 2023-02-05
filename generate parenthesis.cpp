class Solution
{
    private:
    void solve(int n, string &temp, vector<string> &res, int copen, int cclosed, int ropen, int rclosed){
        //base case
        if(cclosed == n && copen == n){
            res.push_back(temp);
            return;
        }
        
        //include '('
        if(ropen > 0){
            temp.push_back('(');
            solve(n, temp, res, copen+1, cclosed, ropen-1, rclosed);
            //backtrack
            temp.pop_back();
        }
        
        //include ')'
        if(rclosed > 0 && cclosed < copen){
            temp.push_back(')');
            solve(n, temp, res, copen, cclosed+1, ropen, rclosed-1);
            //backtrack
            temp.pop_back();
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        string temp = "(";
        int copen = 1;
        int cclosed = 0;
        int ropen = n-1;
        int rclosed = n;
        solve(n, temp, res, copen, cclosed, ropen, rclosed);
        return res;
    }
};
