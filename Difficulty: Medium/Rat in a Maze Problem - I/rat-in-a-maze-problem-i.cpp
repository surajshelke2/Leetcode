//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    vector<string>ans;
    void solve(vector<vector<int>>&mat ,vector<vector<int>>&visited,string temp, int r , int c , int n , int m  ){
        
        // safe zone
        
        if(r<0|| r>=n || c<0 || c>=m || visited[r][c] == 1 || mat[r][c] ==0){
            
            return;
        }
        
        if(r==n-1 && c == m-1){
            
            ans.push_back(temp);
            return;
        }
        
        visited[r][c] = 1;
        
        solve(mat,visited,temp+'U',r-1,c,n,m);
        solve(mat,visited,temp+'R',r,c+1,n,m);
        solve(mat,visited,temp+'D',r+1,c,n,m);
        solve(mat,visited,temp+'L',r,c-1,n,m);
        
        visited[r][c] =0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        if(mat[0][0] ==0) return {};
        
        solve(mat,visited,"",0,0,n,m);
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

// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg