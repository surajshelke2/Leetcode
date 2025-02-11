//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum money the thief can get.
    
    int helper(vector<int>& arr, int i, int n,vector<int>&dp){
        
        
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int include = helper(arr,i+2,n,dp)+arr[i];
        int exclude = helper(arr,i+1,n,dp);
        
        
        return dp[i] = max(include,exclude);
    }
    int findMaxSum(vector<int>& arr) {
        // Your code here
        vector<int>dp(arr.size()+1,-1);
        return helper(arr,0,arr.size(),dp);
    }
};

//{ Driver Code Starts.

int main() {

    // taking total testcases
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

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends