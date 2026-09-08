#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int choice, value, position, i;

    while (true) {
        cout << "\n--- Array Operations ---\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Update Element\n";
        cout << "5. Search Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            display(arr, size);
            break;

        case 2:
            cout << "Enter position (0 to " << size << "): ";
            cin >> position;

            cout << "Enter element: ";
            cin >> value;

            if (position < 0 || position > size) {
                cout << "Invalid position!\n";
                break;
            }

            for (i = size; i > position; i--) {
                arr[i] = arr[i - 1];
            }

            arr[position] = value;
            size++;

            cout << "Element inserted successfully.\n";
            display(arr, size);
            break;

        case 3:
            cout << "Enter position to delete: ";
            cin >> position;

            if (position < 0 || position >= size) {
                cout << "Invalid position!\n";
                break;
            }

            for (i = position; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }

            size--;

            cout << "Element deleted successfully.\n";
            display(arr, size);
            break;

        case 4:
            cout << "Enter position to update: ";
            cin >> position;

            if (position < 0 || position >= size) {
                cout << "Invalid position!\n";
                break;
            }

            cout << "Enter new value: ";
            cin >> value;

            arr[position] = value;

            cout << "Element updated successfully.\n";
            display(arr, size);
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> value;

            for (i = 0; i < size; i++) {
                if (arr[i] == value) {
                    cout << "Element found at index " << i << ".\n";
                    break;
                }
            }

            if (i == size) {
                cout << "Element not found.\n";
            }
            break;

        case 6:
            cout << "Program ended.\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
