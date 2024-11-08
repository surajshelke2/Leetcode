class Solution {
public:
    
    vector<vector<int>>dp;
    int solve(int m , int n , int r , int c ){
        
        if(c== m-1 || r==n-1){
            
            return 1;
        }
        
        if(dp[r][c] != -1) return dp[r][c];
        
       
        
        return dp[r][c] =  solve(m,n,r+1,c)+solve(m,n,r,c+1);
    }
    int uniquePaths(int m, int n) {
        
        dp.resize(n+1,vector<int>(m+1,-1));
        
        return solve(m,n,0,0);
        
        
    }
};