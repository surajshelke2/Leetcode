class Solution {
public:
    void solve(vector<string>&ans ,vector<string>values, string temp ,string digits , int ind){
        
        
        if(digits.size()==ind){
            
            ans.push_back(temp);
            return;
        }
        
        int n = digits[ind]-'0';
        string num = values[n];
        
        for(int i=0;i<num.size();i++){
            
            solve(ans,values,temp+num[i],digits,ind+1);
        }
        
        
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> values = {
            
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        } ;
        
        
        vector<string>ans;
          if(digits.length()==0) return {};
        solve(ans,values,"" ,digits,0);
            
        return ans;
        
        
    }
};