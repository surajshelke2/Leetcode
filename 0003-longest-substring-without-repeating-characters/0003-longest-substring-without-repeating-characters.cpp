class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0;
        int j =0;
        
        int n = s.length();
        unordered_map<char,int>mpp;
        int ans =0 ;
        
        while(j<n){
            
            
           if(mpp.find(s[j]) != mpp.end() && mpp[s[j]] >= i){
                
                i = mpp[s[j]] + 1 ;
               
            }
            
             mpp[s[j]] = j;
            ans = max(ans,j-i+1);
            j++;
     
        }
        
        return ans;
        
    }
};