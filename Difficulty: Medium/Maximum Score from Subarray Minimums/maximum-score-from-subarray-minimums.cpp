//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        
       int n = arr.size();
        if (n < 2) return 0; // No pairs exist in arrays with fewer than 2 elements

        int maxSum = INT_MIN; // Initialize to the smallest possible value
        
        for (int i = 0; i < n - 1; i++) {
            int sum = arr[i] + arr[i + 1]; // Sum of current and next element
            maxSum = max(maxSum, sum);  
        }
        
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends