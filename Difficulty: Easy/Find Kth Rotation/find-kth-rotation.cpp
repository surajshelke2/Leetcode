//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        
        
        int s =0;
        int e = nums.size()-1;
        int ind = -1;
        int ans = INT_MAX;
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(nums[s] <= nums[mid]){
                
                
                if(nums[s] < ans){
                    
                    ans = nums[s];
                    ind = s;
                }
                
                s = mid+1;
                
            }
            else{
                
                
                if(nums[mid] < ans){
                    
                    ans = nums[mid];
                    ind = mid;
                }
                
                e = mid-1;
                
                
                
            }
 
        }
        
        return ind;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends