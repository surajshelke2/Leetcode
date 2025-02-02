//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> map;
        int n = arr.size();
        int prefixSum = 0;
        int longestSubarrayLength = 0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(prefixSum==k){
                longestSubarrayLength = i+1;
            } else{
                int complement = prefixSum - k;
                if(map.find(complement)!=map.end()){
                    longestSubarrayLength = max(longestSubarrayLength,i-map[complement]);
                }
            }
            
            if(map.find(prefixSum)==map.end()){
                map[prefixSum] = i;
            }
        }
        
        return longestSubarrayLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends