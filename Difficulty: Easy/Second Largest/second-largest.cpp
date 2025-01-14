//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        
        
        int maxEle =arr[0];
        int scMax = -1;
        
        
        for(int i=0;i<arr.size();i++){
            
            
            if(arr[i]>maxEle){
                
                scMax = maxEle;
                maxEle = arr[i];
            }
            else if(arr[i]<maxEle && arr[i] > scMax){
                
                scMax = arr[i];
            }
        }
        
        return scMax;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends