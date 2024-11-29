class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n,-1);
      
        
        for(int j=2*n-1;j>=0;--j){
            
            int ind = j%n;
            while(!st.empty() && nums[st.top()] <= nums[ind]){
                
                st.pop();
            }
            
            if(!st.empty()){
                
                ans[ind] = nums[st.top()];
            }
           
            
            st.push(ind);
        }
        
       
        return ans;
    }
};