#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getWidth(TreeNode* root) {
    if (root == nullptr) return 0;

    queue<pair<TreeNode*, int>> q; 
    q.push({root, 0}); 
    unordered_map<int, int> levelCount; 
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();

        levelCount[level]++; 
        if (node->left != nullptr) q.push({node->left, level + 1});
        if (node->right != nullptr) q.push({node->right, level + 1});
    }

    int maxWidth = 0;
    for (auto& entry : levelCount) {
        maxWidth = max(maxWidth, entry.second);
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1); 
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x].push_back(y); 
    }

    
    TreeNode* root = new TreeNode(1);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        int parent = node->val;
        for (int child : tree[parent]) {
            if (!node->left) {
                node->left = new TreeNode(child);
                q.push(node->left);
            } else {
                node->right = new TreeNode(child);
                q.push(node->right);
            }
        }
    }

    int width = getWidth(root);
    cout << width << endl;

    return 0;
}
