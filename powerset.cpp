class Solution{
    private:
        void solve(string s, vector<string> &ans, string temp, int index){
            //base case
            if(index >= s.size()){
                if(temp.length() > 0){
                    ans.push_back(temp);
                }
                return;
            }
            
            //exclude the CHAR
            solve(s, ans, temp, index+1);
            
            //include the CHAR
            temp.push_back(s[index]);
            solve(s, ans, temp, index+1);
        }
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string temp;
		    solve(s, ans, temp, 0);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
