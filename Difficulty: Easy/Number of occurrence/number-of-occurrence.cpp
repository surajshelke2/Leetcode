//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int>& arr , int target , int check){
        
        int s =0;
        int e =arr.size()-1;
        int result= -1;
        
        while(s<=e){
            
            int mid = s+(e-s)/2;
            
            if(arr[mid] < target){
                
                s = mid+1; 
            }
            else if(arr[mid] > target){
                
                e = mid-1;
            }
            else if ( arr[mid] == target){
                
                
                if(check){
                    
                    e = mid-1;
                    
                }
                else{
                    
                    s = mid+1;
                }
            }
        }
        
        return check ? s : e;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int start = solve(arr,target,true);
        int end = solve(arr, target, false);
        
        
        return end - start  + 1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends