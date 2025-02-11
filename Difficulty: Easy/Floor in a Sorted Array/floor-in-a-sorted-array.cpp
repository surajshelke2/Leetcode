//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        
        
        int ans = -1;
        int n = arr.size()-1;
        int s = 0;
        int e = n;
        
        
        if(arr[0] > k) return -1;
        if(arr[n] < k) return -1;
         
        while(s<=e){
            
            int mid = s+(e-s)/2;
            
            if(k < arr[mid]){
                
               
                e = mid-1;
            }
            else{
                
                s  = mid+1;
                ans = mid;
                
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends