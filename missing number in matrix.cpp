class Solution {
    bool row(vector<vector<int> >& matrix, int n){
        int r1 = 0;
        for(int i=0; i<n; i++){
            r1 = r1 + matrix[0][i];
        }
        for(int i=1; i<n; i++){
            int r = 0;
            for(int j=0; j<n; j++){
                r = r + matrix[i][j];
            }
            if(r != r1){
                return false;
            }
        }
        return true;
    }
    bool col(vector<vector<int> >& matrix, int n){
        int c1 = 0;
        for(int i=0; i<n; i++){
            c1 = c1 + matrix[i][0];
        }
        for(int i=1; i<n; i++){
            int c = 0;
            for(int j=0; j<n; j++){
                c = c + matrix[j][i];
            }
            if(c != c1){
                return false;
            }
        }
        return true;
    }
    bool dia(vector<vector<int> >& matrix, int n){
        int d1=0, d2=0;
        for(int i=0; i<n; i++){
            d1 = d1 + matrix[i][n-i-1];
        }
        for(int i=0; i<n; i++){
            d2 = d2 + matrix[i][i];
        }
        if(d1 == d2){
            return true;
        }
        else{
            return false;
        }
    }
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        long long int ans=0, r, c;
        int n = matrix.size();
        
        //capture position of 0
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    r = i;
                    c = j;
                }
            }
        }
        
        //store required number at correct position
        if(r==0){
            for(int i=0; i<n; i++){
                ans = ans + (matrix[1][i] - matrix[0][i]);
            }
            matrix[r][c] = ans;
        }
        else{
            for(int i=0; i<n; i++){
                ans = ans + (matrix[0][i] - matrix[r][i]);
            }
            matrix[r][c] = ans;
        }
        
        //check if sum is equal
        if(row(matrix, n) && col(matrix, n) && dia(matrix, n) && ans>0){
            return ans;
        }
        return -1;
    }
    
};
