class Solution{
private:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int duprow = row;
        int dupcol = col;
        
        while(row >= 0 and col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;col--;
        }
        
        row = duprow;
        col = dupcol;
        
        while(row < n and col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row++;col--;
        }
        
        row = duprow;
        col = dupcol;
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        
        return true;
    }
    
    void helper(int col, vector<string> &board, vector<vector<int>> &ans, int n, vector<int> &row_comb){
        if(col == n){
            ans.push_back(row_comb);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                //action
                board[row][col] = 'Q';
                row_comb.push_back(row+1);
                //recursive call
                helper(col+1, board, ans, n, row_comb);
                //backtrack
                board[row][col] = '.';
                row_comb.pop_back();   
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;     // will contain all comb
        vector<string> board(n, string(n, '.'));    // store and test one comb
        vector<int> row_comb;
        helper(0, board, ans, n, row_comb);
        return ans;
    }
};
