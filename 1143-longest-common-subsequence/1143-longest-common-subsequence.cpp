class Solution {
public:
    vector<vector<int>>dp;
    int solve(string str1 , string str2 , int n , int m){
        
            if(n == 0  || m == 0 ){
                
                return 0;
            }
        
        if(dp[n][m] != -1) return dp[n][m];
        if(str1[n-1] == str2[m-1]){
            
            return dp[n][m] =  1+solve(str1,str2,n-1,m-1);
        }
        else{
            
            return dp[n][m] =  max(solve(str1,str2,n-1,m),
                      solve(str1,str2,n,m-1));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        dp.assign(n+1,vector<int>(m+1,0));
        
        
       
        for(int i=1;i<n+1;i++){
            
            for(int j =1 ;j<m+1 ;j++){
                
                if(text1[i-1] == text2[j-1]){
                    
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};