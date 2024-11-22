class Solution {
public:
  
    int start = 0, maxLength = 1;

    
    void expandAroundCenter(const string &s, int left, int right) {
        
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
          
            if (right - left + 1 > maxLength) {
                
                start = left;
                maxLength = right - left + 1;
            }
           
            left--;
            right++;
        }
    }

   
    string longestPalindrome(string s) {
        if (s.empty()) return ""; 

      
        for (int i = 0; i < s.size(); i++) {
            expandAroundCenter(s, i, i);     
            expandAroundCenter(s, i, i + 1);
        }

       
        return s.substr(start, maxLength);
    }
};
