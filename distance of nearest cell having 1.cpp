class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    //pushing coordinate in queue
	    queue <pair<int, int> > q;
	    
	    //maintain a copy of original grid to keep track of original values 
	    vector<vector<int>>grid2 = grid;
	    
	    int r = grid.size();
	    int c = grid[0].size();
	    
	    for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(grid[i][j] == 1){
	                q.push({i, j});
	            }
	        }
	    }
	    
	    int level = 0, rtemp, ctemp, size;
	    while(!q.empty()){
	        ++level;   //1 step already taken
	        size = q.size();
	        while(size-- > 0){
	            //get row and column of that element of queue
	            rtemp = q.front().first;
	            ctemp = q.front().second;
	            q.pop();
	            
	            //kahin queue ke bahar na chale jaye
	            if(rtemp > 0 && grid[rtemp-1][ctemp] == 0){
	                q.push({rtemp-1, ctemp});
	                grid[rtemp-1][ctemp] = level;
	            }
	            if(ctemp > 0 && grid[rtemp][ctemp-1] == 0){
	                q.push({rtemp, ctemp-1});
	                grid[rtemp][ctemp-1] = level;
	            }
	            if(rtemp < r-1 && grid[rtemp+1][ctemp] == 0){
	                q.push({rtemp+1, ctemp});
	                grid[rtemp+1][ctemp] = level;
	            }
	            if(ctemp < c-1 && grid[rtemp][ctemp+1] == 0){
	                q.push({rtemp, ctemp+1});
	                grid[rtemp][ctemp+1] = level;
	            }
	        }
	    }
	    
	     for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(grid2[i][j] == 1){
	                grid[i][j] = 0;
	            }
	        }
	    }
	    return grid;
	}
};
