//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int N, int k)
    {
        
        
        int s=0;
        int e = N-1;
        int ans =-1;
        if(arr[0] > k) return 0;
        if(arr[e] < k) return N;
        
        while(s<=e){
            
            
            int mid = s+(e-s)/2;
            
            
            if(arr[mid] >= k){
                ans = mid;
                e = mid-1;
            }
            else{
                
                s = mid+1;
              
                
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends