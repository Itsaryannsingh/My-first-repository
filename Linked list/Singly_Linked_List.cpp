```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertAtEnd(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if (head == nullptr)
    {
        head = newNode;
        cout << "Node inserted at end.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Node inserted at end.\n";
}

// Insert at a specific position
void insertAtPosition(Node*& head, int value, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position does not exist.\n";
        return;
    }

    Node* newNode = createNode(value);

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted at position " << position << ".\n";
}

// Delete from beginning
void deleteFromBeginning(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "First node deleted.\n";
}

// Delete from end
void deleteFromEnd(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;

        cout << "Last node deleted.\n";
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    cout << "Last node deleted.\n";
}

// Delete from a specific position
void deleteFromPosition(Node*& head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Position does not exist.\n";
        return;
    }

    Node* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    delete nodeToDelete;

    cout << "Node deleted from position " << position << ".\n";
}

// Search an element
void searchElement(Node* head, int value)
{
    Node* temp = head;
    int position = 1;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "Element found at position "
                 << position << ".\n";
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Element not found.\n";
}

// Display linked list
void displayList(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\nLinked List:\n";

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Main function
int main()
{
    Node* head = nullptr;

    int choice;
    int value;
    int position;

    cout << "========================================\n";
    cout << "     SINGLY LINKED LIST MANAGER\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search Element\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: ";
                cin >> position;

                insertAtPosition(head, value, position);
                break;

            case 4:
                deleteFromBeginning(head);
                break;

            case 5:
                deleteFromEnd(head);
                break;

            case 6:
                cout << "Enter position: ";
                cin >> position;

                deleteFromPosition(head, position);
                break;

            case 7:
                cout << "Enter element to search: ";
                cin >> value;

                searchElement(head, value);
                break;

            case 8:
                displayList(head);
                break;

            case 9:
                cout << "\nProgram exited successfully.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}

