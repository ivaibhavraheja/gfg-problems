class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
    vector<long long int> ans;
    unordered_map<int, bool> row;
    unordered_map<int, bool> col;
    
    long long left = n*n;
    
    int r, c;
    for(int i=0; i<k; i++){
        r = arr[i][0];
        c = arr[i][1];
        long long getOne;
        if(row[r] != 1){
            row[r] = true;
            getOne = n - col.size();
            left = left - getOne;
        }
        if(col[c] != 1){
            col[c] = true;
            getOne = n - row.size();
            left = left - getOne;
        }
        ans.push_back(left);
    }
    return ans;
  }
};
