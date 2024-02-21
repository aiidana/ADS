// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cin >>n;
//     vector<int>v(n);
//     for(int i=0;i<n; i++){
//         cin >> v[i];
//     }
//     int x;
//     cin >>x;


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

TreeNode* findNode(TreeNode* root, int val) {
    if (root == NULL || root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    else return findNode(root->right, val);
}

int countSubtreeNodes(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countSubtreeNodes(node->left) + countSubtreeNodes(node->right);
}

int calculateSubtreeSize(TreeNode* root, int target) {
    TreeNode* targetNode = findNode(root, target);
    if (targetNode != NULL) return countSubtreeNodes(targetNode);
    return -1; // Node not found
}

int main() {
    int N;
    cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }
    int target;
    cin >> target;

    TreeNode* root = NULL;
    for (int i = 0; i < N; ++i) {
        root = insert(root, values[i]);
    }

    int result = calculateSubtreeSize(root, target);
    cout << result << endl;

    return 0;
}
