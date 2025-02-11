//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        
        int s=0;
        int n1 = a.size();
        int n2 = b.size();
         if (n1 + n2 < k) return -1; 
        int i=0;
        int j =0;
        int ans =0;
        
        while(i<n1 && j < n2){
            
            
            
            if(a[i] < b[j]){
                
                ans =a[i];
                i++;
                
            }else{
                
                ans = b[j];
                j++;
            }
            
            s++;
            
            if(s==k) return ans;
            
            
        }
        
        while(s!= k && i<n1){
            
            ans =a[i];
            i++;
            s++;
        }
        
          while(s!= k && j<n2){
            
            ans =b[j];
            j++;
            s++;
        }
        
        if(s==k) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends