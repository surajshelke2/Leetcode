//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int getPerHour(vector<int>& arr, int k, int preH){
        
        int total =0;
        
        for(int i=0;i<arr.size();i++){
            
            total += ceil((double)arr[i] / preH);
          
        }
        
        return total;
    }
    int kokoEat(vector<int>& arr, int k) {
        
        
        
        int s = 1;
        int e = *max_element(arr.begin(),arr.end());
        int ans =1;
        while(s<=e){
            
            int mid = s+(e-s)/2;
            
            if(getPerHour(arr,k,mid) > k){
                
                 s = mid+1;
            }
            else{
                ans = mid;
                e = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends