#include <iostream>
#include <list>
#include <utility>

using namespace std;

const int TABLE_SIZE = 10;

class HashTable
{
private:
    list<pair<int, string>> table[TABLE_SIZE];

    // Hash Function
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:

    // Insert Key-Value
    void insert(int key, string value)
    {
        int index = hashFunction(key);

        // Check if key already exists
        for (auto& item : table[index])
        {
            if (item.first == key)
            {
                item.second = value;
                cout << "Key updated successfully.\n";
                return;
            }
        }

        table[index].push_back({key, value});

        cout << "Key inserted successfully.\n";
    }

    // Search Key
    void search(int key)
    {
        int index = hashFunction(key);

        for (auto& item : table[index])
        {
            if (item.first == key)
            {
                cout << "Key found!\n";
                cout << "Key: " << item.first << endl;
                cout << "Value: " << item.second << endl;
                return;
            }
        }

        cout << "Key not found.\n";
    }

    // Delete Key
    void remove(int key)
    {
        int index = hashFunction(key);

        for (auto it = table[index].begin();
             it != table[index].end();
             ++it)
        {
            if (it->first == key)
            {
                table[index].erase(it);

                cout << "Key deleted successfully.\n";
                return;
            }
        }

        cout << "Key not found.\n";
    }

    // Display Hash Table
    void display()
    {
        cout << "\n===== HASH TABLE =====\n";

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << " -> ";

            for (auto& item : table[i])
            {
                cout << "[" << item.first
                     << ", " << item.second << "] ";
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable hashTable;

    int choice;

    do
    {
        cout << "\n===== HASH TABLE MANAGEMENT =====\n";
        cout << "1. Insert Key-Value\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int key;
            string value;

            cout << "Enter key: ";
            cin >> key;

            cout << "Enter value: ";
            cin >> value;

            hashTable.insert(key, value);

            break;
        }

        case 2:
        {
            int key;

            cout << "Enter key to search: ";
            cin >> key;

            hashTable.search(key);

            break;
        }

        case 3:
        {
            int key;

            cout << "Enter key to delete: ";
            cin >> key;

            hashTable.remove(key);

            break;
        }

        case 4:
            hashTable.display();
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
