//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
   int merge(vector<int>& arr , int l , int mid , int r){
       
       int s= l;
       int j = mid+1;
       int cnt =0;
       
       vector<int>temp;
       while(l <= mid  && j <= r){
           
           if(arr[l] <= arr[j]){
               
               
               temp.push_back(arr[l]);
               l++;
           }
           else {
               
               cnt+=(mid-l+1);
               temp.push_back(arr[j]);
               j++;
               
           }
       }
       
       
       while(l<=mid){
           
           temp.push_back(arr[l]);
           l++;
       }
       
       while(j<= r){
           
           temp.push_back(arr[j]);
           j++;
       }
       
       for(int i=0;i<temp.size();i++){
           
           arr[s] = temp[i];
           s++;
       }
       
       return cnt;
   }
    // Function to count inversions in the array.
    
    int mergeSort(vector<int>& arr , int l , int r){
        
        int cnt=0;
        
        if(l>=r) return cnt;
        
        int mid = l+(r-l)/2;
        
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
        
        cnt+=merge(arr,l,mid,r);
        
        return cnt;
        
        
        
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        
        return mergeSort(arr,0,arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends