//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        
        
        
        
        int maxLen =0;
       
       int n = arr.size();
       for(int i=0;i<n;i++){
           set<int>st;
           for(int j=i;j<n;j++){
               
               st.insert(arr[j]);
               
               if(st.size() <=2){
                   
                   maxLen = max(maxLen,j-i+1);
               }else{
                   
                   break;
               }
           }
       }
       
       return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends