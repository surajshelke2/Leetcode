//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        // code here..
        
        if(p==0 || head == nullptr) return head;
        
        int n =1;
        Node * tail = head;
        while(tail->next){
            n++;
            tail = tail->next;
        }
        
        p = p % n;
        
        if(p==0) return head;
        
        Node * newTail = head;
        for(int i=1;i<p;i++){
            
            newTail = newTail->next;
 
        }
        
        
        Node * newHead = newTail->next;
        newHead->prev = nullptr;
        newTail->next = nullptr;
        tail->next = head;
        head->prev = tail;
        
        return newHead;
        
    }
};

//{ Driver Code Starts.

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int d;
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        // string dummy;
        // cin>>dummy;
        cin.ignore();
        Node *start = NULL, *cur = NULL;

        // Build doubly linked list
        for (int i = 0; i < arr.size(); i++) {
            Node* ptr = new Node(arr[i]);
            if (start == NULL) {
                start = ptr;
                cur = ptr;
            } else {
                cur->next = ptr;
                ptr->prev = cur;
                cur = ptr;
            }
        }

        Solution obj;
        Node* rotatedList = obj.rotateDLL(start, d);
        printList(rotatedList);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends