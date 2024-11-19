class Solution {
public:
    
    void solve(int k , int n , vector<vector<int>>& res , vector<int>& ans , int ind){
        
        
         
        if(n==0  && k==0 ){
            
            res.push_back(ans);
        }
        
        if (k == 0 || n <= 0) {
            return;
        }
        
        
        
        for(int i = ind;i<=9;i++){
            
            ans.push_back(i);
            solve(k-1,n-i,res,ans,i+1);
            ans.pop_back();
            
        }  
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        
        vector<int>temp;
        vector<vector<int>>res;
        solve(k,n,res,temp,1);
        
        return res;
        
    }
};