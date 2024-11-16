//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool solve(vector<int>&arr ,int i , int target,vector<vector<int>>dp){
        
        if(i >= arr.size()) return false;
        if(target==0) return true;
        
        if(dp[i][target] != 0) return dp[i][target];
        
        return dp[i][target] =  solve(arr, i+1 ,target- arr[i],dp) || solve(arr,i+1,target,dp);
    }
    bool isSubsetSum(vector<int>& arr, int target) {
         int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true; 
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends