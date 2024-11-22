class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n = nums1.size();
        int m = nums2.size();
        int total = n+m;
        int i=0;
        int j=0;
        
        int ind1 = total/2;
        int ind2 = (total/2)-1;
        int cnt =0;
        
        int ele1 = -1 ,ele2 = -1;
        
        while(i<n && j<m){
            int current =0;
            if(nums1[i] < nums2[j]){
                
                current = nums1[i];
             
                i++;
            }
            else{
                current = nums2[j];
              
                j++;
           
            }
            
            if(cnt == ind1) ele1 = current;
            if(cnt == ind2) ele2 = current;
            
            cnt++;
        }
        
        
        while(i<n){
            
                if(cnt == ind1) ele1 = nums1[i];
                if(cnt == ind2) ele2 = nums1[i];
                cnt++;
                i++;
            
        }
        
        while(j<m){
            
                if(cnt == ind1) ele1 = nums2[j];
                if(cnt == ind2) ele2 = nums2[j];
                cnt++;
                j++;
        }
        
        if(total %2 == 1){
            
            return (ele1);
        }
        
        
        return (ele1 + ele2)/2.0;
    }
};