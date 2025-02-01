//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

     vector<string>ans;
     
     void solve(int num, string str){
         
         if(num ==0){
             
             ans.push_back(str);
             return;
         }
         
         
         solve(num-1,str+'0');
         if(str.empty() || str.back() != '1')
             solve(num-1,str+'1');
     }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        
        solve(num,"");
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends