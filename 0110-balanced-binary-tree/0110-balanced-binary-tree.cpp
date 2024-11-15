/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int height(TreeNode * root){
        
        if(root == nullptr) return 0;
        
        
        
        return 1 + max(height(root->left),height(root->right)) ;
        
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == nullptr) return true;
        
        int h1 = isBalanced(root->left);
        int h2 = isBalanced(root->right);
        
        int diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(diff && h1 && h2){
            
            return true;
        }
        
        return false;
        
    }
};