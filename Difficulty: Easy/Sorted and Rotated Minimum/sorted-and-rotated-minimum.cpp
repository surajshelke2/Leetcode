//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        
        
        
        
        int s =0;
        int e = arr.size()-1;
        
        int ans =-1;
        while(s<e){
            
            int mid = s+(e-s)/2;
        
             if(mid > 0 && arr[mid] < arr[mid-1]) return arr[mid];
             else if(arr[s] <= arr[mid] && arr[mid] > arr[e]) s = mid+1;
             else e = mid-1;
        }
        
        return arr[s];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends