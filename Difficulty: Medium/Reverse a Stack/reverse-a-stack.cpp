//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insertAtBottom(stack<int>&st , int ele){
        
        if(st.empty()){
            
            st.push(ele);
            return;
        }
        
        int topi = st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(topi);
        
    }
    void Reverse(stack<int> &St){
        
        if(St.empty()) return;
        
        int ele = St.top();
        St.pop();
        
        Reverse(St);
        
        insertAtBottom(St,ele);
        
        
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends