class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        vector<int> ans ;
        
        for(int i=0;i<nums1.size();i++){
            
            int greater= -1;
            for(int j = nums2.size()-1;j>=0;j--){
                if(nums1[i] == nums2[j]) break;
                if(nums1[i] < nums2[j]){
                    
                    greater = nums2[j];
                }
                
                
            }
            
            ans.push_back(greater);

        }
        
        return ans;
    }
};