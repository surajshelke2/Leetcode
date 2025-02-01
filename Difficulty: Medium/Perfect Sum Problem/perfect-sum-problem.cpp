//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int>& arr , int target , int ind,vector<vector<int>>&dp){
        
        if (ind == arr.size()) return (target == 0) ? 1 : 0;

        
        if(dp[ind][target] != -1) return dp[ind][target];
     
        int exclude = solve(arr, target, ind + 1,dp);
      
        int include = (target >= arr[ind]) ? solve(arr, target - arr[ind], ind + 1, dp) : 0;

        return dp[ind][target] = exclude + include;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        
       vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
       return solve(arr,target,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends