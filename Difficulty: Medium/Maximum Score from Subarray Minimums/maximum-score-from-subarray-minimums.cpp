//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        
        int n=arr.size();
     long maxi = 0;
        long currSum = 0;
        for(int i=0;i<n-1;i++) {
            currSum = arr[i] + arr[i+1];//calculate two //adjacent element sum,which includes smallest and //2nd smallest 
            maxi = max(maxi,currSum);//find maximum //two adjacent element sum
        }
        return maxi;    
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