//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countSubstrWithAtMostKDistinct(const string& s, int k) {
        unordered_map<char, int> freq;
        int i = 0, count = 0;
        
        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;  // Add current character to the window
            
            // Shrink the window if the number of distinct characters exceeds k
            while (freq.size() > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) {
                    freq.erase(s[i]);
                }
                i++;  // Move the left pointer to shrink the window
            }
            
            // All substrings ending at `j` and starting from any index between `i` and `j`
            count += (j - i + 1);  // Add the number of valid substrings
        }
        
        return count;
    }
    
    int countSubstr(string& s, int k) {
        if (k == 0) return 0;  // No substrings with exactly 0 distinct characters
        
        return countSubstrWithAtMostKDistinct(s, k) - countSubstrWithAtMostKDistinct(s, k - 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends