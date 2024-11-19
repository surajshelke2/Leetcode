class Solution {
public:
    int solve(int amount ,vector<int>& coins,int index,vector<vector<int>>&dp){
        
        if(amount == 0) return 1;
         if (amount < 0 || index >= coins.size()) return 0;
        if(dp[index][amount] != -1) return dp[index][amount];
        
         int include = solve(amount - coins[index], coins, index,dp);
        int exclude = solve(amount, coins, index + 1,dp);

        return dp[index][amount] = include + exclude; 
        
   
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
        
    }
};