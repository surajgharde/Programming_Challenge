#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;
        
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};

 
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
         if (i < nodes.size() && nodes[i] != INT32_MIN) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
         if (i < nodes.size() && nodes[i] != INT32_MIN) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution solution;

   
    vector<pair<vector<int>, bool>> testCases = {
        {{1, 2, 2, 3, 4, 4, 3}, true},
        {{1, 2, 2, INT32_MIN, 3, INT32_MIN, 3}, false},
        {{1}, true},
        {{}, true},
        {{1, 2, 2, 3, INT32_MIN, INT32_MIN, 3}, false}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        bool result = solution.isSymmetric(root);
        cout << "Test case " << i+1 << ": Output = " << (result ? "true" : "false") 
             << ", Expected = " << (testCases[i].second ? "true" : "false") 
             << ", Passed = " << (result == testCases[i].second ? "Yes" : "No") << endl;
    }

    return 0;
}
