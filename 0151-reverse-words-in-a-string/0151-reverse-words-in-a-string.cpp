class Solution {
public:
    string reverseWords(string s) {
        
        
        stack<string>st;
        
     
   
        int j=0;
        int n = s.size();
        while(j<s.size()){
            
               while (j< n && s[j] == ' ') {
                j++;
            } 
            string word;
            while(j<n && s[j] !=' '){
                
                word += s[j];
                j++;
            }
            
            if (!word.empty()) {
                st.push(word);
            }
        }
        
        
        
        string ans ;
        
        while(!st.empty()){
            
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += ' '; 
            }
        }
        
        return ans;
    }
};