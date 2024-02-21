// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int N;
//     cin >> N;
//     vector<int> values(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> values[i];
//     }
//     int x;
//     cin >> x;

// }
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void printSubtree(TreeNode* root, int k) {
    if (root == NULL) return;
    if (root->val == k) {
        preOrder(root);
        cout << endl;
        return;
    }
    if (root->val > k) printSubtree(root->left, k);
    else printSubtree(root->right, k);
}

int main() {
    int n;
    cin >> n;
    vector<int> gifts(n);
    for (int i = 0; i < n; ++i) {
        cin >> gifts[i];
    }
    int k;
    cin >> k;

    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert(root, gifts[i]);
    }

    printSubtree(root, k);

    return 0;
}
