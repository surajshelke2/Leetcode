class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        
        int start = 0, maxLength = 1;
         auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        };

       
        for (int i = 0; i < s.size(); i++) {
            expandAroundCenter(i, i);     // Odd-length palindromes
            expandAroundCenter(i, i + 1); // Even-length palindromes
        }

    
        return s.substr(start, maxLength);
    }
        
        
    
};