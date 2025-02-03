//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        
        int ele1 = a[0] < b[0] ? a[0] : b[0];
        int ele2;
        int  n= a.size();
        int  m= b.size();
        
        int count = (n+m)/2+1;
        int size = n+m;
        int i=0,j=0;
        
        while(i<n && j<m && count){
            
            
            if(a[i] > b[j]){
                
                ele2 = ele1;
                ele1 = b[j];
                
                j++;
                count--;
            }
            else{
                
                ele2 = ele1;
                 ele1 = a[i];
                
                i++;
                count--;
            }
        }
        
     
        
        while(count && i<n){
            
            count--;
            ele2 = ele1;
            ele1 = a[i];
            
            i++;
        }
        
        while(count && j<m){
            
            count--;
            ele2 = ele1;
            ele1 = b[j];
            
            j++;
        }
        
         if(count==0){
            
            if(size % 2 != 0){
                
                return (double) ele1;
            }
            else if(size % 2 == 0){
                
                return (double)(ele1 + ele2)/2;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOf2(array1, array2);
        if (ans == (int)ans) {
            cout << (int)ans << endl;
        } else {
            cout << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends