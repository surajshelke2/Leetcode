class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
          
          int i=0;
         int j=m;
        
          while(i < n){
              
              nums1[j++] = nums2[i++];
          }
          sort(nums1.begin(),nums1.end());
         
    }
};