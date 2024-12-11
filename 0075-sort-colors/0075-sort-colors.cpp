class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero =0;
        int one =0;
        int two =0;
        
        
        for(int num : nums){
            
            if(num ==0 ){
                
                zero++;
                
            }else if(num ==1){
                
                one++;
            }
            else if(num==2){
                
                two++;
            }
        }
        
        int k=0;
        
        while(zero--){
            
            nums[k++] =0;
        }
        
        while(one--){
            
            nums[k++] =1;
        }
        
        while(two--){
            
            nums[k++]=2;
        }
        
        
    
        
    }
};