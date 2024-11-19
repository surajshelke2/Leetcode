class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>&temp , int n , int i ){
        
        
        if(i ==nums.size()){
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        
        
        solve(nums,ans,temp,n,i+1);
        
        
        temp.push_back(nums[i]);
        solve(nums,ans,temp,n,i+1);
        temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans ;
        vector<int>temp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(nums,ans,temp,n,0);
        
        
        return ans;
    }
};