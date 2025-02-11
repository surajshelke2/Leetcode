//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int firstocc(vector<int>&arr , int s , int e , int x){
       
       int ans = -1;
       while(s<=e){
           
           int mid = s+(e-s)/2;
           
           
           if(arr[mid]==x){
               
               ans = mid;
               e = mid-1;
           }
           else if(x< arr[mid]) {
               
               
               e = mid-1;
           }else{
               
                s = mid+1;               
           }
       }
       
       return ans;
   }
   
   
   int lastOcc(vector<int>&arr , int s , int e , int x){
       
       int ans = -1;
       while(s<=e){
           
           int mid = s+(e-s)/2;
           
           
           if(arr[mid]==x){
               
               ans = mid;
               s = mid+1;
           }
           else if(x< arr[mid]) {
               
               
               e = mid-1;
           }else{
               
                s = mid+1;               
           }
       }
       
       return ans;
   }
   
    vector<int> find(vector<int>& arr, int x) {
        // code here
        
        int first = firstocc(arr,0,arr.size()-1,x);
        int second = lastOcc(arr,0,arr.size()-1,x);
        
        
        return {first,second};
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
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends