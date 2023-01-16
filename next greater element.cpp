class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        stack<long long> s;
        s.push(-1);
        vector<long long> ans(n);
        for(int i=n-1; i>=0; i--){
            long long curr = arr[i];
            while(s.top() != -1 && s.top() <= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    }
};
