#include <iostream>
#include <climits>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* node, long minVal, long maxVal) {
        if (node == NULL) {
            return true;
        }
         
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
         return helper(node->left, minVal, node->val) &&
               helper(node->right, node->val, maxVal);
    }
};

 TreeNode* newNode(int value) {
    return new TreeNode(value);
}

 int main() {
    Solution solution;
 
    TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);
    cout << "Test Case 1: " << solution.isValidBST(root1) << endl;  
    TreeNode* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);
    cout << "Test Case 2: " << solution.isValidBST(root2) << endl; 

 
    TreeNode* root3 = newNode(10);
    root3->left = newNode(5);
    root3->right = newNode(15);
    root3->right->left = newNode(6);
    root3->right->right = newNode(20);
    cout << "Test Case 3: " << solution.isValidBST(root3) << endl; 
    return 0;
}
