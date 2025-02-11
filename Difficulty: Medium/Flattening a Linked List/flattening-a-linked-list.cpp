//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node * mergeSort(Node* node1 , Node * node2){
        
        Node * ans = new Node(0);
        Node * head = ans;
        
        while(node1 && node2){
            
            if(node1->data < node2->data){
                
                ans->bottom = new Node(node1->data);
                node1 = node1->bottom;
                ans = ans->bottom;
            }
            else{
                
                ans ->bottom = new Node(node2->data);
                node2 = node2->bottom;
                ans = ans->bottom;
            }
        }
        
        
        while(node1){
            
            ans->bottom = new Node(node1->data);
            node1 = node1->bottom;
            ans = ans->bottom;
        }
        
         while(node2){
            
            ans->bottom = new Node(node2->data);
            node2 = node2->bottom;
            ans = ans->bottom;
        }
        
        return head->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
       
        if(!root || !root->next) return root;
        
        
        root->next =  flatten(root->next);
        
        return mergeSort(root,root->next);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends