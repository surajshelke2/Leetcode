//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void solve(stack<int>& st , int ele){
    
     if(st.empty() || ele >= st.top()){
         
         st.push(ele);
         return;
     }
     
     
     int topi = st.top();
     st.pop();
     
     solve(st,ele);
     st.push(topi);
}

void help(stack<int>&st ){
    
    if(st.empty()){
        
        return;
    }
    
    int topi = st.top();
    st.pop();
    
    help(st);
    solve(st,topi);
}

void SortedStack :: sort()
{
   //Your code here
   
  
   
   help(s);
   
}