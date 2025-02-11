//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool check(int arr[] , int n ,int perW ,int d ){
        
        int t=1;
        int curr =0;
        for(int i=0;i<n;i++){
            
            if(curr+arr[i] >perW){
                t++;
                curr = arr[i];
                
            }else{
                
                curr +=arr[i];
               
            }
            
            if (t > d) {
                return false;
            }
            
            
        }
        
        return true;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here4
        
        int s = *max_element(arr, arr + n);;
        int sum =0;
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
        }
        
        
        int e = sum;
        int ans =e;
        while(s<=e){
            
            int mid = s+(e-s)/2;
            if (check(arr, n, mid, d)) {
                ans = mid;  
                e = mid - 1;  
            } else {
                s = mid + 1;  
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
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends