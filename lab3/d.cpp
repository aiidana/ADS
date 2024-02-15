#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int count; 
};


void build(vector<int>& a, vector<Node>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node].count = 0; // Initialize count to 0 for leaf nodes
        return;
    }
    int mid = (start + end) / 2;
    build(a, tree, 2 * node, start, mid);
    build(a, tree, 2 * node + 1, mid + 1, end);
    tree[node].count = tree[2 * node].count + tree[2 * node + 1].count; // Combine counts of child nodes
}

int query(vector<Node>& tree, int node, int start, int end, int l, int r) {
    if (start > r || end < l) return 0; 
    if (start >= l && end <= r) return tree[node].count; 
    int mid = (start + end) / 2;
    return query(tree, 2 * node, start, mid, l, r) + query(tree, 2 * node + 1, mid + 1, end, l, r); 
}

int main() {
    int n, q;
    cin >> n >> q;

    
    vector<int> a(n);
    vector<Node> tree(4 * n); 
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    build(a, tree, 1, 0, n - 1);

    
    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        
        int count = query(tree, 1, 0, n - 1, l1 - 1, r1 - 1) + query(tree, 1, 0, n - 1, l2 - 1, r2 - 1);
        cout << count << endl;
    }

    return 0;
}
