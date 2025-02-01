//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string>ans;
   
    
    void solve(vector<vector<int>>&mat , int n , int m , int row , int col , string temp,vector<vector<int>>&visited){
        
        
        if(0 > row || 0 > col || row >= n || col >=m || mat[row][col] ==0 || visited[row][col] == 0) return ;
        
        
        if(row == n-1 && col == m-1){
            
            ans.push_back(temp);
            return;
        } 
        
        visited[row][col] =0;
        solve(mat,n,m,row-1,col,temp+'U',visited);
        solve(mat,n,m,row+1,col,temp+'D',visited);
        solve(mat,n,m,row,col+1,temp+'R',visited);
        
        solve(mat,n,m,row,col-1,temp+'L',visited);
        
        visited[row][col] =1;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return ans;
        }
        
         vector<vector<int>>visited(n,vector<int>(m,1));
        solve(mat,mat.size(),mat[0].size(),0,0,"",visited);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends