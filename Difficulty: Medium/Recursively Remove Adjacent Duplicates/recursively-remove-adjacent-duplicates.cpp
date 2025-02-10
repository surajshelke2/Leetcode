//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string removeUtil(string &s) {
        // code here
        
       string ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[i] == s[j]) {
                j++;
            }
            
            if (j == i + 1) {
                ans += s[i];
            }
            i = j;  
        }
        
        // If changes were made, call recursively
        if (ans != s) {
            return removeUtil(ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        s = ob.removeUtil(s);
        if (s.size() == 0)
            cout << "\"\"";
        else
            cout << s << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends