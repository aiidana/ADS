#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

void deleteSecondStream(Node* head) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count % 2 != 0 && current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
        count++;
    }
}

// Функция для печати списка
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> n;

    // Создаем список
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Enter value for node " << i + 1 << ": ";
        std::cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "Original linked list: ";
    printLinkedList(head);

    // Удаляем каждый второй элемент из списка
    deleteSecondStream(head);

    std::cout << "Linked list after deleting second stream: ";
    printLinkedList(head);

    // Очищаем память, выделенную для узлов списка
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     vector<int>v(n);
//     for(int i=0; i<n;i++){
//         cin >> v[i];
//     }
//     for(int i=0; i<n;i++){
//         if(i%2==0){
//             cout << v[i]<<" ";
//         }
//     }
// }
