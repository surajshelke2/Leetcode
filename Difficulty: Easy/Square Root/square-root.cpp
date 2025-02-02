//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        
        
        if(n ==0 || n ==1) return n;
        int ans =-1;
        
        int s = 0;
        int e = n;
        
        while(s<=e){
            
            
            int mid = s+(e-s)/2;
              if(mid*mid == n){
                
                return mid;
            }
            
            if(mid*mid < n){
                
                ans = mid;
                s = mid+1;
            }
            else{
                
                e = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends