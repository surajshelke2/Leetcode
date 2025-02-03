//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    
    bool isPresent(vector<int>& arr , int x){
        
        
        int s =0;
        int e =arr.size()-1;
        
        while(s<=e){
            
            int mid = s +(e-s)/2;
            
            if(arr[mid] == x){
                
                return true;
            }
            
            if(arr[mid] < x){
                
                s = mid+1;
            }
            else{
                
                e = mid-1;
            }
        }
        
        return false;
    }
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        
        
        
        for(auto it : mat){
            
            if(it[0] <= x  && x <= it[it.size()-1]){
                
                if(isPresent(it,x)){
                    
                    return true;
                }
                 break;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends