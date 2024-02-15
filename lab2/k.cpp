
// #include <iostream>
// #include <queue>
// #include <unordered_map>

// using namespace std;

// void findFirstNonRepeatingChar(const string& stream) {
//     unordered_map<char, int> countMap;
//     queue<char> charQueue;

//     for (char ch : stream) {
//         countMap[ch]++;

//         charQueue.push(ch);

//         while (!charQueue.empty() && countMap[charQueue.front()] > 1) {
//             charQueue.pop();
//         }

//         if (!charQueue.empty()) {
//             cout << charQueue.front() << " ";
//         } else {
//             cout << "-1 ";
//         }
//     }

//     cout << endl;
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int N;
//         cin >> N;

//         string stream;
//         cin >> stream;

//         findFirstNonRepeatingChar(stream);
//     }

//     return 0;
// }

#include <iostream>
#include <map> 

using namespace std;

struct Node {
    char val;
    Node* next;
    Node() {}
    Node(char val) {
        this->val = val;
        next = NULL;
    }
};

void push(Node* &end, Node* &head, int val) {
    if(end == NULL) {
        head = new Node(val);
        end = head;
        return;
    }
    end->next = new Node(val);
    end = end->next;
}


int main() {
    int n;
    cin >> n;
    
    while(n--) {
        int c;
        cin >> c;
        Node* head = nullptr;
        Node* end = head;
        map <char, int> m;
        while(c--) {
            char val;
            cin >> val;
            push(end, head, val);
            m[val]++;

            Node* cur = head;
            bool first = false;
            while(cur) {
                if(m[cur->val] == 1) {
                    first = true;
                    break;
                }
                cur = cur->next;
            }
            if(first) cout << cur->val << " ";
            else cout << -1 << " ";
        }
        m.clear();
        cout << endl;
    }
}
