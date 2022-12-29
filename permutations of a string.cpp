class Solution
{
    void solve(string s, vector<string> &ans, int index){
        //base case
        if(index >= s.length()){
            ans.push_back(s);
            return;
        }
        for(int i=index; i<s.length(); i++){
            swap(s[index], s[i]);
            solve(s, ans, index+1);
            //backtracking
            swap(s[index], s[i]);
        }
    }
    
	public:
		vector<string>find_permutation(string s)
		{
		    vector<string> ans ;
		    int index = 0;
		    solve(s, ans, index);
		    sort(ans.begin(), ans.end());
		    //for keeping only unique elements
		    ans.erase(unique(ans.begin(), ans.end()), ans.end());
		    return ans;
		}
};
