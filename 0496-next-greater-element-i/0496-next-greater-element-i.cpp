class Solution {
public:
    
    void NGR(vector<int>& num1 , unordered_map<int,int>&store){
        
         int j= num1.size()-1;
        
        stack<int>st;
        
        while(j>=0){
           
            while(!st.empty() && st.top() <= num1[j]){
                
                 st.pop();
            }
            
           if (st.empty()) {
                store[num1[j]] = -1;
            } else {
               
                store[num1[j]] = st.top();
            }
            
            st.push(num1[j]);
            j--;
        }
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int , int>store;
        
        NGR(nums2,store);
        
        vector<int>ans;
        
        for(int i=0;i<nums1.size();i++){
            
            ans.push_back(store[nums1[i]]);      
            
        }
        
        return ans;
    }
};