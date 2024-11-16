class Solution {
public:
 
    int solve(vector<vector<int>>& grid , int r , int c , int n , int m , vector<vector<int>>dp){
        
       
        
         if( r > n  || c>m || grid[r][c] == 1){
            
            return 0;
          } 
        
        if(r==n && c == m) return 1;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        return dp[r][c] = solve(grid,r,c+1,n,m,dp) + solve(grid,r+1,c,n,m,dp);
        
        
        

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,0));
        // return solve(grid,0,0,grid.size()-1,grid[0].size()-1,dp);
        
        dp[0][0] = (grid[0][0]==0);
        for(int i = 0 ;i<n;i++){
            
            for(int j =0;j<m;j++){
                
                if(grid[i][j] == 1) continue;

                if(i>0) dp[i][j] += dp[i-1][j] ;
                if(j>0) dp[i][j] += dp[i][j-1] ;
            }
        }
        
        
        return dp[n-1][m-1];
        
    }
};