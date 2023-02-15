class Solution 
{
    private:
    bool isSafe(int k, int row, int col, int grid[N][N]){
        for(int i=0; i<9; i++){
            //rowcheck
            if(grid[row][i] == k)
                return false;
            //colcheck
            if(grid[i][col] == k)
                return false;
            //3x3 matrix check
            if(grid[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == k)
                return false;
        }
        return true;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int row=0; row<N; row++){
            for(int col=0; col<N; col++){
                if(grid[row][col] == 0){
                    for(int k=1; k<=9; k++){
                        if(isSafe(k, row, col, grid)){
                            //action
                            grid[row][col] = k;
                            bool nextAns = SolveSudoku(grid);
                            if(nextAns)
                                return true;
                            //backtrack
                            else
                                grid[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        if(SolveSudoku(grid)){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    cout << grid[i][j] << " ";
                }
            }
        }
    }
};
