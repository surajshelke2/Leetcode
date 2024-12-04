//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &v) {
        // code here
        
        
         sort(v.begin(), v.end());
        
        int floor = -1; 
        int ceil = -1; 
        
 
        auto lower = lower_bound(v.begin(), v.end(), x);
        if (lower != v.end()) {
            ceil = *lower; 
        }
        
       
        auto upper = upper_bound(v.begin(), v.end(), x);
        if (upper != v.begin()) {
            floor = *(--upper); 
        }
        
        return {floor, ceil};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends