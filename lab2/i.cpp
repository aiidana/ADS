#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string bookName;
    Node* prev;
    Node* next;

    Node(const string& name) : bookName(name), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addFront(const string& bookName) {
        Node* newNode = new Node(bookName);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok" << endl;
    }

    void addBack(const string& bookName) {
        Node* newNode = new Node(bookName);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok" << endl;
    }

    string eraseFront() {
        if (!head) {
            return "error";
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        string erasedBook = temp->bookName;
        delete temp;
        return erasedBook;
    }

    string eraseBack() {
        if (!tail) {
            return "error";
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        string erasedBook = temp->bookName;
        delete temp;
        return erasedBook;
    }

    void printFront() {
        if (!head) {
            cout << "error" << endl;
            return;
        }
        cout << head->bookName << endl;
    }

    void printBack() {
        if (!tail) {
            cout << "error" << endl;
            return;
        }
        cout << tail->bookName << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    string command;
    while (true) {
        cin >> command;
        if (command == "add_front") {
            string bookName;
            cin >> bookName;
            dll.addFront(bookName);
        } else if (command == "add_back") {
            string bookName;
            cin >> bookName;
            dll.addBack(bookName);
        } else if (command == "erase_front") {
            cout << dll.eraseFront() << endl;
        } else if (command == "erase_back") {
            cout << dll.eraseBack() << endl;
        } else if (command == "front") {
            dll.printFront();
        } else if (command == "back") {
            dll.printBack();
        } else if (command == "clear") {
            dll.clear();
        } else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}
