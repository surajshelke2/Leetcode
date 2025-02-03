//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(vector<int>&v ,vector<int>&dp , int n ){
        
        if(n==0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int left  = fun(v,dp,n-1) + abs(v[n]-v[n-1]);
        int right = INT_MAX;
        
        if(n > 1) right = fun(v,dp,n-2) + abs(v[n]-v[n-2]);
        
        return dp[n] = min(left,right);
        
        
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int v = height.size();
        vector<int>dp(v+1,-1);
        
        return fun(height,dp,v-1);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends