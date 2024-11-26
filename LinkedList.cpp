
#include <iostream>
using namespace std;
template <class BatuhanOzcil>
class LinkedList {
  
    struct Node {
        BatuhanOzcil data;
        Node* next;
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void Add(BatuhanOzcil value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " added to the list.\n";
    }

    void Delete(BatuhanOzcil value) {
        Node* temp = head;
        Node* prev = nullptr;

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (head->data == value) {
            head = head->next;
            delete temp;
            cout << value << " deleted from the list.\n";
            return;
        }

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << value << " not found in the list.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << value << " deleted from the list.\n";
    }

    void Search(BatuhanOzcil value) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found in the list.\n";
                return;
            }
            temp = temp->next;
        }

        cout << value << " not found in the list.\n";
    }

    void Print() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;
    int choice, value;

    cout << "================BatuhanOzcil================\n";
    cout << "~~ WELCOME to Linked List program ~~\n";
    cout << "=============================================\n";

    do {
        cout << "\nSelect and Enter Your Choice from the Menu:\n";
        cout << "=============================================\n";
        cout << "1. Add\n2. Delete\n3. Search\n4. Print\n5. Exit\n";
        cout << "=============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to add: ";
            cin >> value;
            list.Add(value);
            break;
        case 2:
            cout << "Enter the value to delete: ";
            cin >> value;
            list.Delete(value);
            break;
        case 3:
            cout << "Enter the value to search: ";
            cin >> value;
            list.Search(value);
            break;
        case 4:
            list.Print();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 5);

    return 0;
}
