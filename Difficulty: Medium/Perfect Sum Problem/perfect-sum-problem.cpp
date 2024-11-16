//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int solve(int *arr , int sum ,int i , int n,vector<vector<int>>&dp){
	    
	     if(sum == 0 && i==n ) return 1;
	     if(i >= n || sum < 0 ) return 0;
	    
	    if(dp[i][sum] != -1 ) return dp[i][sum];
	    
	    int notTake =  solve(arr, sum , i+1, n,dp);
	    int take = 0;
	    
	    if(sum >= arr[i])
	        take = solve(arr,sum - arr[i] , i+1 , n,dp );
	   
	   
	    
	    return dp[i][sum] = (take +notTake )%mod;
	    
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
      
       vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       
       return solve(arr,sum,0,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends