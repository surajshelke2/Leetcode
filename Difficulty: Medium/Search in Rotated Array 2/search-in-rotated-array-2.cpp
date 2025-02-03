//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool Search(vector<int>& arr, int k) {
        // Code here
        
        
        int s =0;
        int e = arr.size()-1;
        
        int ans =-1;
        while(s<=e){
            
            int mid = s+(e-s)/2;
            
            if(arr[mid] == k){
                
                return true;
            }
            else if(arr[mid] > k){
                
                 e = mid-1;
            }else{
                
                s = mid+1;
            }
            
           
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.Search(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends