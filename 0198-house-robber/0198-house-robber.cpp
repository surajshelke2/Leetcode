class Solution {
public:
    int solve(vector<int>& nums , vector<int>& dp , int n ){
        
        if(n==0) return 0;
        
        if(n==1) return nums[0];
        
        if(dp[n] != -1) return dp[n];
        
        int notTake = solve(nums, dp, n-1);
        int take = nums[n-1] + solve(nums, dp , n-2);
        
        dp[n] =max(take,notTake);
            
        return dp[n];
    }
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size()+1,-1);
        
        return solve(nums,dp,nums.size());
        
        
    }
};