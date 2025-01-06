//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
 
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        unordered_map<int,int>mpp;
        vector<int>ans={-1,-1};
        for(auto it:arr){
            
            mpp[it]++;
        }
        
        
        for(int i=1;i<=arr.size();i++){
            
            if(mpp.find(i) == mpp.end()){
                
                ans[1] = i;
            }
            
            if(mpp[arr[i-1]] >1){
                
                ans[0] = arr[i-1];
            }
        }
        
        
        if(ans[0]==-1){
            
            ans[0] = arr[arr.size()]+1;
        } 
        
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
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends