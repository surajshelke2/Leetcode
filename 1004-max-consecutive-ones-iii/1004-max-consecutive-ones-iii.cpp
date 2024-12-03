class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        
        int zero=0;
        
        int n = nums.size();
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<n){
            
            if(nums[j]==0) zero++;
            
            while(zero >k){
                
               
                    
                    if(nums[i]==0) zero--;
                    i++;
               
            }
         
                
                maxlen = max(maxlen,j-i+1);
                
            
            j++;
        }
        
        return maxlen;
        
    }
};