//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   void dfs(vector<vector<int>>&adj , int node ,vector<bool>&visited){
       
       
            visited[node] = true;
            
            for(auto it : adj[node]){
                
                if(!visited[it]){
                    
                    dfs(adj,it,visited);
                }
            }
   }
    int numProvinces(vector<vector<int>> adj, int V) {

        vector<vector<int>>graph(V);
        
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            
            for(int j=0;j<V;j++){
                
                if(adj[i][j] == 1  && i != j){
                    
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        int count =0;
        
        for(int i=0;i<V;i++){
            
            
            if(visited[i]==false){
                count++;
                dfs(graph,i,visited);
            }
        }
        
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends