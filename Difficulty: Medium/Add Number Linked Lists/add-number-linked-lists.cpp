//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node * reverse(Node * node){
        
        Node * prev = nullptr;
        Node * curr = node;
        
        
        while(curr){
            
            Node * next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        
   
        Node * n1 = reverse(num1);
        Node * n2 = reverse(num2);
        Node * ans = new Node(0);
        Node * ansH = ans;
        int carray =0;
        while(n1 != nullptr || n2 != nullptr || carray !=0 ){
            
            int v1 = (n1)?n1->data:0;
            int v2 = (n2)?n2->data:0;
            
            int sum = v1+v2+carray;
            
            carray = sum / 10;
            ans->next = new Node(sum%10);
            ans = ans->next;
            if(n1) n1 = n1->next;
            if(n2) n2 = n2->next;
            
        }
        
        
         Node* result = reverse(ansH->next);
        
        // Remove leading zeros (except when the result is exactly zero)
        while (result && result->data == 0 && result->next) {
            result = result->next;
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends