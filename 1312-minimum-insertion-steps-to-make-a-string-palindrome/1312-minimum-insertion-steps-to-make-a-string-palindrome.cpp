class Solution {
public:
    int minInsertions(string s1) {
        
        int n = s1.size();
        
        string s2 = s1;
        
        reverse(s2.begin(),s2.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      
        
        for(int i=1;i<n+1;i++){
            
            for(int j =1;j<n+1;j++){
                
                if(s1[i-1] ==  s2[j-1]){
                    
                    dp[i][j] = 1 +dp [i-1][j-1];
                }else{
                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        
        int len =  dp[n][n];
        
        return n-len;
        
    }
};