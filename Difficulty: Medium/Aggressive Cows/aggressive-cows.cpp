//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canSet(vector<int>& stalls ,int dist ,int k){
        
         int cow = 1;
         int lastPlaced = stalls[0];
         
         for(int i=1;i<stalls.size();i++){
             
             if(stalls[i]-lastPlaced >= dist){
                 
                 cow++;
                 lastPlaced = stalls[i];
             }
             
             
             if(cow == k){
                 
                 return true;
             }
         }
         return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
         int n = stalls.size();
         if(n < k) return 0;
        sort(stalls.begin(),stalls.end());
       
        int s = 1;
        int e = stalls[n-1] - stalls[0];
        int ans = 0;
        while(s<=e){
            
            
            int mid = s + (e-s)/2;
            
            if(canSet(stalls,mid,k)){
                
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends