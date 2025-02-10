//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    
    int solve(vector<int>&wt,vector<int>&val,int capacity, vector<vector<int>>&dp, int n ){
        
        if(capacity ==0 || n==0) return 0;
        
        if(dp[n][capacity] != -1) return dp[n][capacity];
        if(wt[n-1] > capacity){
            
            dp[n][capacity] = solve(wt,val,capacity,dp,n-1);
        }
        else if(wt[n-1] <= capacity){
            
            dp[n][capacity] = max(val[n-1] + solve(wt,val,capacity-wt[n-1],dp,n-1),
            solve(wt,val,capacity,dp,n-1));
        }
        
        return dp[n][capacity];
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
        return solve(wt,val,capacity,dp,n);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends