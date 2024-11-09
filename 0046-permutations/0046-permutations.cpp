class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&num , int n ,int ind ){
        
        if(ind==n-1){
            
            ans.push_back(num);
            return;
        };
        
        
        for(int i=ind;i<n;i++){
            
            swap(num[i],num[ind]);
            solve(num,n,ind+1);
            swap(num[i],num[ind]);
            
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        solve(nums,nums.size(),0);
        return ans;
    }
};