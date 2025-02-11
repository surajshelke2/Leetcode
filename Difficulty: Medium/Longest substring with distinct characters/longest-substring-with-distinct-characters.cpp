//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &arr) {
        // code here
        
        string temp;
        
        unordered_set<char>st;
        int i=0;
        int j=0;
        int maxCount=0;
        while(j<arr.size()){
            
             
           while(st.find(arr[j]) != st.end()){
               st.erase(arr[i]);
               i++;
           }
            
            st.insert(arr[j]);
           
            maxCount = max(maxCount,j-i+1);
            j++;
        }
        
        return maxCount;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends