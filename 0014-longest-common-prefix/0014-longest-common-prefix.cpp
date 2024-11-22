class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
         if (strs.empty()) {
            return "";
        }
        
       string ans ;
        int n = strs[0].size();
        string temp = strs[0];
       for(int i=0;i<n;i++){
           
           
           for(auto str : strs){
               
               
                if(i >= str.size() || str[i] != temp[i]){
                    
                   
                    return ans;
                }
               
           }
           
           ans += temp[i];
       }
        
        
        return ans;
        
    }
};